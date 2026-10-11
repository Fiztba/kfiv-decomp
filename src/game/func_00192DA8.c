#include "common.h"

typedef struct {
    u8 count;
    char pad1[0xB];
    u16 *thresholds; /* u16 values at a stride of 0x12 bytes */
} Entry;

typedef struct {
    char pad0[0x78];
    u64 low : 39;
    u64 level : 7;
    u64 high : 18;
} Slot;

typedef struct {
    char pad0[0xF0];
    u16 num_slots;
    char padF2[6];
    Slot *slots; /* 0x80-byte slots */
    Entry **tables;
} Owner;

/* Stores in each slot's 7-bit field how many thresholds the value passed. */
int func_00192DA8(Owner *arg0, int arg1, int arg2) {
    Entry *entry;
    Slot *slot;
    int i, v;
    u16 *t;

    entry = *(Entry **)((char *)arg0->tables + (arg1 << 2));
    for (i = 0; i < arg0->num_slots; i++, entry++) {
        slot = &arg0->slots[i];
        if (entry->thresholds == NULL || entry->count == 0) {
            continue;
        }
        t = entry->thresholds;
        for (v = 0; v < entry->count; v++, t += 9) {
            if (arg2 < *t) {
                break;
            }
        }
        if (v == entry->count) {
            slot->level = 0;
        } else if (v != 0) {
            slot->level = v - 1;
        }
    }
    return 1;
}
