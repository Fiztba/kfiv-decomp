#include "common.h"

extern char D_0043F730[];

typedef struct {
    void (*fn[3])(void *);
} HandlerTable;

typedef struct {
    char pad[0x1C];
    int index;
    int flag;
} Owner;

/* Call the handler selected by owner->index unless owner->flag is set. */
void func_001D4360(Owner *owner) {
    HandlerTable handlers = *(HandlerTable *)D_0043F730;

    if (owner->flag == 0) {
        handlers.fn[owner->index](owner);
    }
}
