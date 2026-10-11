#include "common.h"

typedef struct {
    float unk00;
    int unk04;
    char pad08[4];
    float unk0C;
} Entry;

extern char D_00471DE0[];

void func_00111D00(void) {
    Entry *entry = (Entry *)D_00471DE0;
    int i;

    for (i = 0; i < 16; i++) {
        entry->unk00 = 0.01f;
        entry->unk04 = 0;
        entry->unk0C = (float)i * 6.2831855f * 0.0625f;
        entry++;
    }
}
