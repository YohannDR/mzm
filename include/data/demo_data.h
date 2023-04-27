#ifndef DEMO_DATA_H
#define DEMO_DATA_H

#include "structs/demo.h"
#include "structs/save_file.h"

#define MAX_AMOUNT_OF_DEMOS 16

extern const struct SaveDemo sDemo0_Ram;
extern const struct SaveDemo sDemo1_Ram;
extern const struct SaveDemo sDemo2_Ram;
extern const struct SaveDemo sDemo3_Ram;
extern const struct SaveDemo sDemo4_Ram;
extern const struct SaveDemo sDemo5_Ram;
extern const struct SaveDemo sDemo6_Ram;
extern const struct SaveDemo sDemo7_Ram;
extern const struct SaveDemo sDemo8_Ram;
extern const struct SaveDemo sDemo9_Ram;
extern const struct SaveDemo sDemo10_Ram;
extern const struct SaveDemo sDemo11_Ram;
extern const struct SaveDemo sDemo12_Ram;
extern const struct SaveDemo sDemo13_Ram;
extern const struct SaveDemo sDemo14_Ram;
extern const struct SaveDemo sDemo15_Ram;

extern const struct DemoEntry sDemoEntries[MAX_AMOUNT_OF_DEMOS];

extern const u8 sDemoNumbers[MAX_AMOUNT_OF_DEMOS];

#endif /* DEMO_DATA_H */
