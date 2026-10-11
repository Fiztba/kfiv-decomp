#include "common.h"

void func_00190A30(char *);
void func_00195898(char *, int);
void func_0019A310(char *, void (*)(void), int);
extern void func_001816A0(void);

typedef struct {
    char pad0[0xD8];
    unsigned long long flags;
} Actor;

typedef struct {
    char pad0[0x68];
    short f68;
} ActorSub;

void func_0014E068(char *arg0) {
    Actor *a = (Actor *)arg0;
    ActorSub *s = (ActorSub *)(arg0 + 0xE0);
    unsigned long long f;
    unsigned long long state;

    func_00190A30(arg0);
    a->flags &= ~0x200;
    f = a->flags;
    state = (f >> 36) & 3;
    if (state == 2) {
        func_0019A310(arg0, func_001816A0, 0);
    }
    func_00195898(arg0, 2);
    s->f68 = 0;
}
