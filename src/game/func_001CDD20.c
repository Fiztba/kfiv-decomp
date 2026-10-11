#include "common.h"

int func_001CBAE0();
extern char *D_004471D4;

typedef struct {
    int unk0;
    char pad4[8];
    int unkC;
    char pad10[8];
    short unk18;
    char pad1A;
    char unk1B;
    int unk1C;
} Slot;

typedef struct {
    char pad0[8];
    int unk8;
    int unkC;
} Entry;

int func_001CDD20(int arg0) {
    Slot *slot = (Slot *)(D_004471D4 + (arg0 << 5));
    Entry *entry = (Entry *)(D_004471D4 + 0x200);
    int result = 0;
    int i;

    slot->unk1C = 1;
    if (*(unsigned short *)(D_004471D4 + 0x4D6) != 0) {
        func_001CBAE0(1, 0x50);
    }
    if (func_001CBAE0(1, 0x1010, slot->unk18, slot->unkC, slot->unk0, slot->unk1B) != 0) {
        result = -1;
    }
    for (i = 4; --i != -1; entry++) {
        if (entry->unk8 == arg0) {
            if (func_001CBAE0(1, 0x2070, entry->unkC, slot->unkC, slot->unk0, slot->unk1B, 1) != 0) {
                result = -1;
                break;
            }
        }
    }
    if (*(unsigned short *)(D_004471D4 + 0x4D6) != 0) {
        func_001CBAE0(1, 0x40);
    }
    return result;
}
