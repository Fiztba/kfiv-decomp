#include "common.h"

char *func_001267B0(int);

void func_002166F8(int *arg0) {
    char *ent;
    long flags;

    ent = func_001267B0(arg0[2]);
    if (ent != NULL) {
        flags = *(long *)(ent + 0xD8);
        if (((flags & 3) == 3) && (*(unsigned short *)(ent + 0x82) == 0) && ((flags & ((0x30L << 32) | 0xC)) == 0)) {
            *(long *)(ent + 0xD8) = flags & ~0x40000;
        }
    }
    arg0[0] = 0;
}
