# Metroid - Zero Mission Decomp

This is a work in progress decompilation of Metroid - Zero Mission.

2718/2721 functions decompiled (99.89%, [3 left](docs/non_matching_functions.md))

0x76b014/0x76b014 bytes of data not in blobs (100%, 0 left)

This repository can be used to build multiple ROMs. The ROMs are named like this: `mzm_{region}.gba` (or `mzm_{region}_debug.gba`)

Region indicates which region the ROM targets:
- us: USA, North America `sha1: 5de8536afe1f0078ee6fe1089f890e8c7aa0a6e8`
- eu: Europe `sha1: 0fd107445a42e6f3a3e5ce8c865f412583179903`
- jp: Japan `sha1: 096f07685a3dc9286e71aa0b761f233b5efa2fcd`
- cn: China **(Not yet supported)**
- us_beta: USA beta version `sha1: 58986c4d6f2e5ccdc04936cc8b7c9d378570710c`
- eu_beta: Europe beta version `sha1: 3c0b7ccd303c30ac5c4ffc9fb0aa7137a533ad69`

Debug simply indicates whether the ROM contains the debug features, it is optional.

The default built ROM is mzm_us.gba

**Discords**: 
- https://discord.gg/2MGB9Xbr9y Metroidret
- https://discord.gg/WtekHKb MAGConst

## Dependencies

- [agbcc](https://github.com/jiangzhengwenjz/agbcc)
- `binutils-arm-none-eabi`
- A baserom for each ROM desired to be built (i.e.`mzm_us_baserom.gba` if you wish to build `mzm_us.gba`).
- `python3`
- `g++`

## Setup

- **WINDOWS ONLY**: Install and setup [WSL](https://docs.microsoft.com/en-us/windows/wsl/install)
- Run `sudo apt update` just in case
- Install `binutils-arm-none-eabi` by running this command: `sudo apt install binutils-arm-none-eabi` or `sudo dnf install arm-none-eabi-binutils-cs`
- Install `git` by running this command: `sudo apt install git` or `sudo dnf install git`
- Install `make` by running this command: `sudo apt install make` or `sudo dnf install make`
- Clone [agbcc](https://github.com/jiangzhengwenjz/agbcc) by running this command: `git clone https://github.com/jiangzhengwenjz/agbcc.git`
- Enter the agbcc folder (run `cd agbcc`) and build it (run `./build.sh`)
- Either:
  - Install agbcc into this project (by using its `./install.sh <path>` script, where `<path>` is the path to the root of this repository), or
  - Add agbcc to your path (`export PATH="<agbcc_path>:$PATH"`, where `<agbcc_path>` is the full path to the agbcc directory)

## Build

- Run `make tidy` if necessary
  - Use `make tidy DATA=1` to remove data as well
- Run the data extractor if necessary: `make extract`
  - For regions other than `us`, specify it using `REGION` (ex: `REGION=jp`)
  - Also run `python3 tools/extractor.py -d` if you want to build a ROM with debug features
- Run `make` (using the `-j` option is recommended to speed up the process)
- To build another version of the ROM you can do either of the following:
  - Specify it directly (ex: `make us_debug` for the US ROM with debug features)
  - Specify the flags, `REGION` (takes the region name, defaults to `us`) and `DEBUG` (takes 0 or 1, defaults to 0)
- Optionally, you can combine the commands to make it easier: `make extract && make -j`

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md)
