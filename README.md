# Metroid - Zero Mission Decomp

This is a work in progress decompilation of Metroid - Zero Mission.
Progress can be seen here : https://docs.google.com/spreadsheets/d/1X8XarD5evY8ZI7r_GQqh1pYmdVMbBcINYfRBUlogmKY/edit#gid=0

**It's very likely that the code of this repo doesn't build, and even if it does it probably won't match, this is normal**

This produces the following ROMs:

- mzm_us.gba: `sha1: 5de8536afe1f0078ee6fe1089f890e8c7aa0a6e8`

**Discords**: 
- https://discord.gg/2MGB9Xbr9y MAGret
- https://discord.gg/WtekHKb MAGConst

## Dependencies

- [agbcc](https://github.com/pret/agbcc)
- `binutils-arm-none-eabi`
- `mzm_us_baserom.gba` (`sha1: 5de8536afe1f0078ee6fe1089f890e8c7aa0a6e8`)

## Setup

- **WINDOWS ONLY** : Install and setup [WSL](https://docs.microsoft.com/en-us/windows/wsl/install)
- Install the dependencies (an `apt update` might be necessary for binutils)
- Build agbcc (run `./build.sh`)
- Add agbcc to your path (export PATH="agbcc path:$PATH"
- Clone this repo

## Build

- Run `make clean` if necessary
- Run `make CPP=cpp` (using the -j option is recommended to speed up the process)
