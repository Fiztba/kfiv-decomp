#include "common.h"

extern int D_00446858;
extern unsigned char D_00446896;
extern char D_004FF558[];

int func_001CEF48(char);
int func_001CEE78(int, short, short, short, short, short, short, int);

typedef struct {
    int flags;
    short a;
    short b;
    short c;
    short d;
    short e;
    short f;
} Entry;

int func_0019F188(void *arg0, int arg1) {
    Entry *entry;

    if (arg1 == 0x12) {
        D_00446858 += 1;
        return 0;
    }
    if (D_00446896 < 4U) {
        func_001CEF48((char)D_00446896);
    }
    entry = (Entry *)(D_004FF558 + arg1 * 0x10);
    D_00446896 = func_001CEE78(entry->flags, entry->a, entry->b, entry->c, entry->d, entry->e, entry->f, 0);
    D_00446858 += 1;
    return 0;
}
