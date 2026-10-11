#include "common.h"

extern unsigned char D_004470A0[8];

/* Returns the index of the first clear bit among the 60 flag bits, or -1. */
int func_001246A8(void) {
    unsigned char *flags = D_004470A0;
    int i;
    int j;
    unsigned char bit;

    for (i = 0; i < 8; i++, flags++) {
        bit = 1;
        for (j = 0; j < 8 && i * 8 + j < 60; j++) {
            if (!(*flags & bit)) {
                return i * 8 + j;
            }
            bit <<= 1;
        }
    }
    return -1;
}
