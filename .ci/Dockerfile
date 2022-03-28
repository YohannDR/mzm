FROM ubuntu:latest

RUN apt-get update -y && \
    apt-get upgrade -y

# Install dependencies needed
RUN apt-get install -y --no-install-recommends \
        binutils-arm-none-eabi \
        build-essential \
        ca-certificates \
        clang-format \
        git \
        make

# Build agbcc
RUN git clone https://github.com/pret/agbcc /opt/agbcc
WORKDIR /opt/agbcc
RUN git checkout faa413e # version from 2022-01-26
RUN ./build.sh

# Add agbcc to PATH
ENV PATH="/opt/agbcc:${PATH}"
