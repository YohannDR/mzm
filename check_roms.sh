#!/bin/bash

set -e
set -o pipefail

cleanup() {
    echo "Cleaning up files"
    make clean DATA=1 > /dev/null
    rm -f err.log
}
trap cleanup EXIT

# regions=("us" "jp" "us_beta")
regions=("us" "jp")

for region in "${regions[@]}"; do
    echo "---- Building for REGION=$region ----"

    echo "* Running: make clean DATA=1"
    if ! make clean DATA=1 > /dev/null 2>err.log; then
        echo "make clean failed"
        cat err.log
        exit 1
    fi

    echo "* Running: python3 tools/extractor.py -r $region"
    if ! python3 tools/extractor.py -r "$region" > /dev/null 2>err.log; then
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

    echo "REGION=$region built successfully"
    echo
done
