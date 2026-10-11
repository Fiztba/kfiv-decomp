#include "common.h"

extern int D_0044733C;

void *memset(void *, int, u32);

typedef struct {
    char flag0;
    char flag1;
    char pad2[2];
    int words[10];
    char pad2c[0x178 - 0x2C];
    int tail[2];
} Entry;

void func_001FBAC8(void) {
    Entry *e;
    int i;

    for (i = 0; i < 3; i++) {
        e = (Entry *)(D_0044733C + i * 0x180);
        e->words[9] = e->words[8] = e->words[7] = e->words[6] = e->words[5] = e->words[4] = e->words[3] = e->words[2] = e->words[1] = e->words[0] = e->flag1 = e->flag0 = 0;
        memset(e->tail, 0, 8);
    }
}
