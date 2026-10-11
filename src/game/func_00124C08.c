#include "common.h"

typedef struct Ent {
    char pad0[0x18];
    struct Ent *prev;
    struct Ent *next;
} Ent;

extern Ent *D_004470A8;
extern Ent *D_004470AC;
extern int D_004470B8;

Ent *func_00124C08(Ent *e) {
    Ent *next;

    next = e->next;
    if (D_004470A8 == e) {
        D_004470A8 = next;
    }
    if (D_004470AC == e) {
        D_004470AC = e->prev;
    }
    if (e->prev != NULL) {
        e->prev->next = next;
    }
    if (e->next != NULL) {
        e->next->prev = e->prev;
    }
    D_004470B8--;
    return next;
}
