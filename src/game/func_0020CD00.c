#include "common.h"

extern char D_00431CE8[];
extern char D_00432820[];
extern int D_00446ED4;
extern int D_00446EF0;

void func_0020CD00(void) {
    int *counters;

    if (D_00432820[0x213] == 0) {
        if (*(int *)(D_00432820 + 0x288) & 0x200) {
            if (D_00432820[0x214] == 0 && (D_00446ED4 & 3) == 0) {
                counters = (int *)D_00431CE8;
                counters[2] = counters[2] + 1;
            }
        } else if (D_00432820[0x214] == 0) {
            counters = (int *)D_00431CE8;
            counters[2] = counters[2] + 1;
        }
    }
    if (D_00446EF0 & 0x400) {
        counters = (int *)D_00431CE8;
        counters[2] = counters[2] + 0x3B;
    }
}
