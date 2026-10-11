#include "common.h"

extern u8 D_00413F80[];
extern u8 D_0041B9B8[];

typedef struct {
    char pad0[0x82];
    u16 f82;
} Ctl;

typedef struct {
    char pad0[0xFC];
    Ctl *fFC;
} Dev;

extern Dev *D_00446978;

void func_00109098(Dev *, u8, u16);
int func_0019CDA0(int);

/* Kick off a request once the flag at 0x261 is clear and the table entry at 0x63 is not 2. */
void func_001BC058(void) {
    Dev *dev;

    if (D_00413F80[0x261] == 0 && D_0041B9B8[D_00413F80[0x3C] * 0x90 + 0x63] != 2) {
        func_0019CDA0(2);
        dev = D_00446978;
        D_00413F80[0x261] = 1;
        func_00109098(dev, 0, dev->fFC->f82);
    }
}
