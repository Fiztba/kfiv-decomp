#include "common.h"

typedef struct {
    char pad[0x430];
    s16 unk430;
} Ctl;

typedef struct {
    char pad[0x68];
    s16 unk68;
} Sub;

typedef struct {
    char pad0[0xC];
    Ctl *ctl;
    char pad1[0x5C - 0x10];
    int unk5C;
    char pad2[0xD8 - 0x60];
    u64 b0 : 18;
    u64 b18 : 1;
    u64 b19 : 1;
    u64 b20 : 1;
    u64 b21 : 1;
    u64 b22 : 42;
    Sub sub;
} Actor;

int rand(void);
void func_00190A30(char *);
void func_00195898(char *, int);
void func_0019A310(char *, void (*)(void), int);
void func_0013D820(void);

void func_0013D778(Actor *arg0) {
    Sub *sub = &arg0->sub;
    int rnd = rand();

    sub->unk68 = arg0->ctl->unk430 / 2 + rnd % arg0->ctl->unk430;
    arg0->b20 = 1;
    arg0->b18 = 1;
    arg0->b21 = 1;
    func_00190A30((char *)arg0);
    arg0->unk5C = 0;
    func_0019A310((char *)arg0, func_0013D820, 0);
    func_00195898((char *)arg0, 2);
}
