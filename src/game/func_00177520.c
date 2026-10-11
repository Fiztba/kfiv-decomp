#include "common.h"

extern float D_00413F84[];

double atan2(double, double);
float func_00194FB8(float);
float func_00195388(float *, float, float);

typedef struct {
    char pad0[0x50];
    float f50;
} Slot;

typedef struct {
    char pad0[0xC4];
    float fC4;
    char padC8[0x30];
    char *pF8;
} Obj;

typedef struct {
    char pad0[0x48];
    float f48;
} Sub;

typedef struct {
    Obj *obj;                   /* 0x00 */
    char pad04[0x08];
    char *ctrl;                 /* 0x0C */
    char pad10[0x54];
    float f64;                  /* 0x64 */
    char pad68[0x78];
    Sub sub;                    /* 0xE0 */
} Actor;

/* Aim: turn the angle toward the target into a clamped value, smooth it, and copy it to the slot. */
void func_00177520(Actor *actor) {
    Obj *o = actor->obj;
    Slot *slot = (Slot *)(o->pF8 + (*(s16 *)(actor->ctrl + 0x434) << 7));
    Sub *sub = &actor->sub;
    float a;

    if (slot != NULL) {
        a = func_00194FB8(atan2(D_00413F84[0] - o->fC4, actor->f64));
        if (0.87266463f < a) {
            a = 0.87266463f;
        } else if (a < -0.87266463f) {
            a = -0.87266463f;
        }
        func_00195388(&sub->f48, a, 10.0f);
        slot->f50 = sub->f48;
    }
}
