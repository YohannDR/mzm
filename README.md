# Metroid - Zero Mission Decomp

This is a work in progress decompilation of Metroid - Zero Mission.

2710/2721 functions decompiled (99.60%, 11 left)

0x76b014/0x76b014 bytes of data not in blobs (100%, 0 left)

Progress can be seen here : https://docs.google.com/spreadsheets/d/1X8XarD5evY8ZI7r_GQqh1pYmdVMbBcINYfRBUlogmKY/edit#gid=0

This repository can be used to build multiple ROMs :

The ROMs are named like this : `mzm_{region}.gba` (or `mzm_{region}_debug.gba`)

Region indicates which region the ROM targets :
- us : USA, North America `sha1: 5de8536afe1f0078ee6fe1089f890e8c7aa0a6e8`
- eu : Europe **(Not yet supported)**
- jp : Japan `sha1: 096f07685a3dc9286e71aa0b761f233b5efa2fcd`
- cn : China **(Not yet supported)**
- us_beta : USA beta version `sha1: 58986c4d6f2e5ccdc04936cc8b7c9d378570710c`

Debug simply indicates whether the ROM contains the debug features, it is optional.

The default built ROM is mzm_us.gba

**Discords**: 
- https://discord.gg/2MGB9Xbr9y MAGret
- https://discord.gg/WtekHKb MAGConst

## Dependencies

- [agbcc](https://github.com/jiangzhengwenjz/agbcc)
- `binutils-arm-none-eabi`
- A baserom for each ROM desired to be built (i.e.`mzm_us_baserom.gba` if you wish to build `mzm_us.gba`).
- `python3`
- `g++`

## Setup

- **WINDOWS ONLY** : Install and setup [WSL](https://docs.microsoft.com/en-us/windows/wsl/install)
- Run `sudo apt update` just in case
- Install `binutils-arm-none-eabi` by running this command : `sudo apt-get install binutils-arm-none-eabi`
- Install `git` by running this command : `sudo apt-get install git`
- Install `make` by running this command : `sudo apt-get install make`

- Clone [agbcc](https://github.com/jiangzhengwenjz/agbcc) by running this command : `git clone https://github.com/jiangzhengwenjz/agbcc`
- Enter the agbcc folder (run `cd agbcc`) and build it (run `./build.sh`)
- Add agbcc to your path (`export PATH="<agbcc_path>:$PATH"`, where `<agbcc_path>` is the full path to the agbcc directory)
- Locate yourself in the decompilation root, and then build preproc (run `cd tools/preproc && make`)

## Build

- Run `make clean` if necessary
  - Use `make clean DATA=1` to remove data as well
- Run the data extractor if necessary : `python3 tools/extractor.py`
  - Use the `-r` flag to specify a region other than `us` (ex: `-r jp`)
  - Use the `-d` flag to extract only debug data from the US beta ROM (required for building a ROM with debug features)
- Run `make` (using the `-j` option is recommended to speed up the process)
- To build another version of the ROM you can do either of the following :
  - Specify it directly (ex: `make us_debug` for the US ROM with debug features)
  - Specify the flags, REGION (takes the region name, defaults to `us`) and DEBUG (takes 0 or 1, defaults to 0)
- Optionally, you can combine the commands to make it easier : `python3 tools/extractor.py && make -j`
