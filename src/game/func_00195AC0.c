#include "common.h"

int func_00195B68(void *, void *, int, int, int, float);

typedef struct {
    char pad_00[0xD4];
    float unkD4;
    char pad_D8[8];
    float unkE0;
} Heading;

typedef struct {
    Heading *heading;
} Mover;

typedef struct {
    char pad_00[0xE];
    short unk0E;
} TurnCmd;

/* Turns the heading by a signed angle and wraps the result to [-pi, pi]. */
int func_00195AC0(Mover *arg0, TurnCmd *arg1, int arg2, int arg3, int arg4) {
    Heading *h = arg0->heading;
    float delta = (float)arg1->unk0E * 0.017453292f;
    float angle;

    if (!(h->unkE0 >= 0.0f)) {
        delta = -delta;
    }
    angle = h->unkD4 + delta;
    angle = angle - (float)(int)(angle / 6.2831855f) * 6.2831855f;
    if (3.1415927f < angle) {
        angle -= 6.2831855f;
    } else if (angle < -3.1415927f) {
        angle += 6.2831855f;
    }
    return func_00195B68(arg0, arg1, arg2, arg3, arg4, angle);
}
