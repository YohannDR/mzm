# Important
Anyone wanting to contribute *MUST* read the following and adhere to the steps
outlined, in order to not violate any copyright.

This decompile is a [clean room design](https://en.wikipedia.org/wiki/Clean_room_design).
It *MUST* not incorperate any code owned by Nintendo or other third parties.

In order to achieve this, all code has to be written completely fresh, without
reference to any third party code, no matter if leaked or not.

Derived from this there is the following requirement for contributors:

- Contributors *MUST NOT* study or refer to any code owned by Nintendo or other
  third parties.

# Decompiling

Before starting any decompilation, make sure the project builds correctly:

```
$ make check
```

Then these are the rough steps to decompile a function:

1. Pick a function to decompile (from `asm/disasm_*.s`)
2. Create a new file in `src/` if necessary (also adjust `linker.ld`)
3. Go through it, roughly line by line, and translate it into C (into the proper file in `src/`)
4. Compile it, see what doesn't match, and change it
5. Repeat step 4 until everything matches (`make diff` can be helpful, as well as https://cexplore.karathan.at/ and https://decomp.me/)
6. Follow the steps in [Submitting a Change](#submitting-a-change)

# Submitting a Change
1. Clone this repository and follow the setup instructions if you haven't already
2. For any set of changes you want to submit, create a branch off of `master` (make sure you're on the latest commit)
3. When ready to submit your changes, make sure the ROM still compiles (`make`)
4. If the ROM compiles, make sure the ROM still matches the base ROM (`make check`)
- Recommended: run `./check_roms.sh` to build and check ROMs for every supported region (may require `chmod +x check_roms.sh`). You will need a base ROM for each supported region.
5. Open a PR on github, and add a description that summarizes your changes
