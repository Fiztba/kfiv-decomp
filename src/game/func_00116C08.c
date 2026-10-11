#include "common.h"

typedef struct {
    u8 bits[0x20];
    u8 tags[0x10];
    u8 values[0x10];
} Block;

typedef struct {
    char unk0;
    u8 tag;
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
