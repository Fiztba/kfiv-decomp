#include "common.h"

typedef struct {
    char pad00[0x20];
    float unk20;
} ObjSub;

typedef struct {
    char pad00[0xE8];
    float unkE8;
} Ctl;

typedef struct {
    char pad00[0x10];
    ObjSub sub;                 /* 0x10 */
    char pad34[0x4C - 0x34];
    u16 unk4C;
    char pad4E[2];
    Ctl *unk50;
} Obj;

void func_001AEC48(void *);
void func_001AED58(void *);
void func_001AF0B0(char *);

/* Advances the counter at +0x4C and scales the controller's float at +0xE8 by sub.unk20 / 1000. */
void func_001AC1F8(Obj *arg0) {
    ObjSub *sub;
    Ctl *ctl;

    func_001AEC48(arg0);
    sub = &arg0->sub;
    func_001AED58(arg0);
    func_001AF0B0(arg0);
    ctl = arg0->unk50;
    arg0->unk4C = arg0->unk4C + 1;
    ctl->unkE8 = ctl->unkE8 * (sub->unk20 / 1000.0f);
}
