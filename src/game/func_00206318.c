#include "common.h"

typedef struct {
    unsigned long X : 16;
    unsigned long Y : 16;
    unsigned long Z : 32;
} Xyz;

typedef struct {
    Xyz a;
    long pad8;
    Xyz b;
    char pad18[0x20 - 0x18];
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
    char pad24[0x3F - 0x24];
    signed char f3F;
    char pad40[0x60 - 0x40];
} S;

extern S D_005DDB80;

/* Copies the packet and greys its colour to 0x40 when its slot matches. */
S *func_00206318(S *arg0, int arg1) {
    D_005DDB80 = *arg0;
    if (arg0->f3F == arg1) {
        D_005DDB80.red = 0x40;
        D_005DDB80.green = 0x40;
        D_005DDB80.blue = 0x40;
    }
    return &D_005DDB80;
}
