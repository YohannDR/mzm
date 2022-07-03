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

# Install dotnet
RUN apt-get update; \
    apt-get install -y apt-transport-https && \
    apt-get update && \
    apt-get install -y dotnet-sdk-6.0

# Build agbcc
RUN git clone https://github.com/pret/agbcc /opt/agbcc
WORKDIR /opt/agbcc
RUN git checkout faa413e # version from 2022-01-26
RUN ./build.sh

# Download and build extractor
RUN git clone https://github.com/YohannDR/MZM-Extractor /opt/MZM-Extractor
WORKDIR /opt/MZM-Extractor/MZM-Extractor/MZM-Extractor
# Compile
RUN dotnet publish -c release --self-contained --runtime linux-x64 --framework net6.0
# Copy to repo
RUN cp -r bin/release/net6.0/linux-x64/publish ../../../mzm/MZM-Extractor

# Add agbcc to PATH
ENV PATH="/opt/agbcc:${PATH}"
