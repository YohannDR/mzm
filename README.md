# Metroid - Zero Mission Decomp

This is a work in progress decompilation of Metroid - Zero Mission.

**It's very likely that the code of this repo doesn't build, and even if it does it probably won't match, this is normal**

This produces the following ROMs:

- mzm_us.gba: `sha1: 5de8536afe1f0078ee6fe1089f890e8c7aa0a6e8`

**Discord**: https://discord.gg/2MGB9Xbr9y

## Dependencies

- [agbcc](https://github.com/pret/agbcc) (make sure it's in your PATH!)
- `binutils-arm-none-eabi`
- `mzm_us_baserom.gba` (`sha1: 5de8536afe1f0078ee6fe1089f890e8c7aa0a6e8`)
- `dotnet`
- [MZM-Extractor](https://github.com/YohannDR/MZM-Extractor)

## Build

To build the ROM: `make`.

Anything else: `make help`.
