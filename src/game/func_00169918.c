#include "common.h"

void func_00190A30(char *);
void func_00195898(char *, int);
void func_0019A310(char *, void (*)(void), int);
void func_00169990(void);

typedef struct {
    char pad0[0x5C];
    int f5C;
    char pad1[0xD8 - 0x60];
    u64 flags;
} Actor;

/* When the state field in flags is 2, resets the actor and registers func_00169990; then sets state 2. */
void func_00169918(char *arg0) {
    Actor *a = (Actor *)arg0;

    if (((a->flags >> 36) & 3) == 2) {
        func_00190A30(arg0);
        a->f5C = 0;
        a->flags &= ~0x400;
        a->flags &= ~0x200;
        func_0019A310(arg0, func_00169990, 0);
    }
    func_00195898(arg0, 2);
}
