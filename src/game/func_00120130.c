#include "common.h"

typedef struct {
    char pad[0x24];
    u32 unk24_b0 : 1;
    u32 unk24_b1 : 1;
} A;

typedef struct {
    char pad[0x50];
    void *cur;
} B;

void func_0011FDD0(void *, int);
extern A D_0038CC50;
extern B D_00420D00;

/* Sets D_0038CC50 bit 1 and makes arg0 the current entry while func_0011FDD0 runs. */
void func_00120130(char *arg0, int arg1) {
    void *saved;
    int bit;

    if ((*(u32 *)(arg0 + 0x10) & 0x2FF00) == 0x100 && arg1 != 0) {
        saved = D_00420D00.cur;
        bit = D_0038CC50.unk24_b1;
        D_0038CC50.unk24_b1 = 1;
        D_00420D00.cur = arg0;
        func_0011FDD0(arg0, arg1);
        D_00420D00.cur = saved;
        D_0038CC50.unk24_b1 = bit;
    }
}
