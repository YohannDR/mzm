# Important
Anyone wanting to contribute *MUST* read the following and adhere to the steps
outlined, in order to not violate any Copyright.

This decompile is a [clean room design](https://en.wikipedia.org/wiki/Clean_room_design).
It *MUST* not incorperate any code owned by Nintendo or other third parties.

In Order to achieve this all code has to be written completely fresh, without
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

1. pick a function to decompile (from `asm/disasm_*.s`)
2. create a new file in `src/` if necessary (also adjust `linker.ld`)
3. go through it, roughly line by line, and translate it into C (into the proper file in `src/`)
4. compile it, see what doesn't match, and change it
5. repeat step 4. until everything matches (`make diff` can be helpful, as well as https://cexplore.karathan.at/ and https://decomp.me/)
6. make sure everything still works (`make check` should give you OK)
7. open a PR on github
