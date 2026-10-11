#include "common.h"

typedef struct {
    int base_offset;
    char pad04[0xC];
    u64 bits;
} Entry;

/* Adds the deltas to two 14-bit fields packed in entry->bits; returns the data base. */
void *func_0020DB48(Entry *entry, int delta_a, int delta_b) {
    u64 bits = entry->bits;
    int field_a;
    int field_b;

    field_a = ((int) (bits & 0x3FFF) + delta_a) & 0x3FFF;
    bits &= ~0x3FFFUL;
    bits |= field_a;
    field_b = (int) ((bits >> 37) & 0x3FFF);
    bits &= 0xFFF8001FFFFFFFFFUL;
    bits |= (u64) ((field_b + delta_b) & 0x3FFF) << 37;
    entry->bits = bits;
    return (char *) entry + entry->base_offset;
}
