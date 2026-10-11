#include "common.h"

void func_001AF928(void *, int);
void func_001AF640(void *, int);
void func_001AF538(float, void *, void *);

/* Re-seeds the sub-object from its linked controller, then sets bit 58 of the flags at +0x40. */
void func_001AE278(char *arg0, int arg1) {
    char *sub;

    sub = arg0 + 0x10;
    func_001AF928(arg0, arg1);
    func_001AF640(arg0, arg1);
    func_001AF538(*(float *)(*(char **)(arg0 + 0x54) + 0xD8), sub, *(char **)(arg0 + 0x50) + 0xD0);
    *(long *)(arg0 + 0x40) |= (long)0x8000 << 0x2B;
}
