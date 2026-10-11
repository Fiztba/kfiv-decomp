#include "common.h"

char *func_001267B0(int);

void func_002166F8(int *arg0) {
    char *ent;
    s64 flags;

    ent = func_001267B0(arg0[2]);
    if (ent != NULL) {
        flags = *(s64 *)(ent + 0xD8);
        if (((flags & 3) == 3) && (*(u16 *)(ent + 0x82) == 0) && ((flags & ((0x30L << 32) | 0xC)) == 0)) {
            *(s64 *)(ent + 0xD8) = flags & ~0x40000;
        }
    }
    arg0[0] = 0;
}
