#!/bin/bash

set -e
set -o pipefail

cleanup() {
    echo "Cleaning up files"
    make tidy DATA=1 > /dev/null
    rm -f err.log
}
trap cleanup EXIT

regions=("us" "eu" "jp" "us_beta" "eu_beta")

for region in "${regions[@]}"; do
    echo "---- Building for REGION=$region ----"

    echo "* Running: make tidy DATA=1"
    if ! make tidy DATA=1 > /dev/null 2>err.log; then
        echo "make tidy failed"
        cat err.log
        exit 1
    fi

    echo "* Running: make extract REGION=$region"
    if ! make extract REGION="$region" > /dev/null 2>err.log; then
        echo "extractor failed for REGION=$region"
        cat err.log
        exit 1
    fi

    echo "* Running: make $region -j"
    if ! make "$region" -j > /dev/null 2>err.log; then
        echo "make $region failed"
        cat err.log
        exit 1
    fi

    echo "* Running: make check REGION=$region"
    if ! make check REGION="$region" > /dev/null 2>err.log; then
        echo "make check failed for REGION=$region"
        cat err.log
        exit 1
    fi

    echo "REGION=$region built successfully!"
    echo
done
