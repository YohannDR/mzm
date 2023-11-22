# Metroid - Zero Mission Decomp

This is a work in progress decompilation of Metroid - Zero Mission.

2673/2721 functions decompiled (98.24%, 48 left)

0x76b014/0x76b014 bytes of data not in blobs (100%, 0 left)

Progress can be seen here : https://docs.google.com/spreadsheets/d/1X8XarD5evY8ZI7r_GQqh1pYmdVMbBcINYfRBUlogmKY/edit#gid=0

**This decomp is not shiftable, don't use it as a base to work on anything**

This produces the following ROMs:

- mzm_us.gba: `sha1: 5de8536afe1f0078ee6fe1089f890e8c7aa0a6e8`

**Discords**: 
- https://discord.gg/2MGB9Xbr9y MAGret
- https://discord.gg/WtekHKb MAGConst

## Dependencies

- [agbcc](https://github.com/jiangzhengwenjz/agbcc)
- `binutils-arm-none-eabi`
- `mzm_us_baserom.gba` (`sha1: 5de8536afe1f0078ee6fe1089f890e8c7aa0a6e8`)
- `python3`
- `g++`

## Setup

- **WINDOWS ONLY** : Install and setup [WSL](https://docs.microsoft.com/en-us/windows/wsl/install)
- Install the dependencies (an `apt update` might be necessary for binutils)
- Build agbcc (run `./build.sh`)
- Add agbcc to your path (export PATH="agbcc path:$PATH")
- Build preproc (run `make` in tools/preproc)

## Build

- Run `make clean` if necessary
- Run the `extractor` script in tools (`./tools/extractor`) if necessary
- Run `make` (using the -j option is recommended to speed up the process)
