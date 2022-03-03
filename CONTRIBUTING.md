# Decompiling

These are the rough steps to decompile a function:

1. pick a function to decompile (from `asm/`)
2. make sure it's not one of the few hand-written functions that can't be decompiled
3. go through it, roughly line by line, and translate it into C (into the proper file in `src/`)
4. adjust `linker.ld` if required
5. compile it, see what doesn't match, and change it
6. repeat step 4. until everything matches (`make diff` can be helpful, as well as https://cexplore.karathan.at/ and https://decomp.me/)
7. make sure everything still works (`make check` should give you OK)
8. open a PR on github
