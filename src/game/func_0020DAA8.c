#include "common.h"

char *func_0020D0B0(char *, int);

typedef struct {
    int unk0;
    u32 entry_count;
    char pad08[0x10 - 0x8];
} TableHeader;

typedef struct {
    int offset; /* from the table base */
    char pad04[0x10 - 0x4];
} TableEntry;

/* Walks a chunk table, handing each entry's chunk to func_0020D0B0; returns the read cursor. */
char *func_0020DAA8(char *base, int arg1) {
    char *cursor;
    TableHeader *header;
    TableEntry *entry;
    u32 i;

    cursor = base;
    header = (TableHeader *)cursor;
    cursor += sizeof(TableHeader);
    entry = (TableEntry *)cursor;
    cursor += header->entry_count * sizeof(TableEntry);
    for (i = 0; i < header->entry_count; i++) {
        cursor = func_0020D0B0((char *)(entry[i].offset + (int)base), arg1);
    }
    return cursor;
}
