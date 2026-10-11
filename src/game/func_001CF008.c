#include "common.h"

int func_001CBAE0();
extern char *D_004471D4;

typedef struct {
    char b[24];
} Rec;

typedef struct {
    char pad[0x440];
    Rec tab[4];
    Rec cur;
} G;

/* Copy entry arg0 (0-4) of the table into the current record, then pass it to func_001CBAE0. */
void func_001CF008(unsigned int arg0) {
    if (arg0 < 5) {
        ((G *)D_004471D4)->cur = ((G *)D_004471D4)->tab[arg0];
        func_001CBAE0(0, 0x40070, &((G *)D_004471D4)->cur);
    }
}
