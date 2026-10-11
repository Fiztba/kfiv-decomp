#include "common.h"

typedef struct {
    unsigned char bits[0x20];
    unsigned char tags[0x10];
    unsigned char values[0x10];
} Block;

typedef struct {
    char unk0;
    unsigned char tag;
    char pad2[0x18 - 0x2];
    Block *blocks;
    char pad1C[0x60 - 0x1C];
} Slot;

extern Slot D_0038CD20[];

/* Tests a flag bit in this slot's block, or looks it up among the 16 entries tagged with another slot. */
int func_00116C08(int slot, int index, int other_slot, int bit) {
    Block *block = D_0038CD20[slot].blocks + index;
    int other_offset = other_slot * 0x60; /* byte offset: retail multiplies before the branch */
    int i;

    if (slot == other_slot) {
        return (block->bits[bit / 8] >> (bit - bit / 8 * 8)) & 1;
    }
    for (i = 0; i < 0x10; i++) {
        if (block->tags[i] == ((Slot *)((char *)D_0038CD20 + other_offset))->tag && block->values[i] == bit) {
            return 1;
        }
    }
    return 0;
}
