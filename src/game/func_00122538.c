#include "common.h"

typedef struct {
    int unk00[6];
    int fired;
} SlotSub;

typedef struct {
    char pad00[8];
    char *unk08;
    char pad0C[4];
    u8 unk10;
    u8 unk11;
    char pad12[0x2E];
    SlotSub sub;
} Slot;

typedef struct {
    u8 unk00;
    u8 unk01;
    char pad02[0x5E];
} MapRow;

typedef struct {
    u8 type;
    char pad01[0x1F];
} Def20;

extern MapRow D_0038CD20[];
extern Def20 D_0041A6F8[];

int func_00103BA8(int, int, int);
void func_00122600(void *, int);

/* Fires the slot's one-shot trigger when its type matches; returns whether it fired. */
int func_00122538(Slot *arg0, int arg1) {
    u8 type;
    MapRow *row;
    int kind;
    SlotSub *s = &arg0->sub;

    type = D_0041A6F8[arg1].type;
    row = &D_0038CD20[arg0->unk10 & 1];
    kind = row->unk01;
    if (arg0->unk11 == 1 && s->fired == 0 && type == arg0->unk11 &&
        func_00103BA8(kind, (u8)arg0->unk08[0x3A], arg1)) {
        func_00122600(arg0, arg1);
        s->fired = type;
        return TRUE;
    }
    return FALSE;
}
