#include "common.h"

typedef struct {
    u64 X : 16;
    u64 Y : 16;
    u64 Z : 32;
} Xyz;

typedef struct {
    Xyz a;
    s64 pad8;
    Xyz b;
    char pad18[0x60 - 0x18];
} S;

extern S D_005DDC40;

S *func_002063E0(S *arg0, int arg1) {
    int step;

    D_005DDC40 = *arg0;
    step = (arg1 * 11) << 4;
    D_005DDC40.a.Y += step;
    D_005DDC40.b.Y += step;
    return &D_005DDC40;
}
