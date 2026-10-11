#include "common.h"

typedef struct {
    u64 a;
    u64 b;
} Pair;

extern Pair D_0043E8B0;
extern int D_00413F80[];

float func_00194FB8(float);
int func_0018E3D0(void *, int, int, int, void *, int, float);

void func_0013D588(char *actor) {
    char pad[0x10]; /* unused, but retail reserves the 0x10 bytes */
    Pair tmp;
    char *model;
    char *joint;
    float angle;

    tmp = D_0043E8B0;
    model = *(char **)actor;
    joint = *(char **)(model + 0xF8) + 0x180;
    if (joint != NULL && *(char *)(actor + 0xD1) == 0x11) {
        func_0018E3D0(model, (int)joint, (int)(actor + 0x110), 1, D_00413F80, 0, 10.0f);
        angle = *(float *)(joint + 0x50) - 2.0943952f;
        *(float *)(joint + 0x50) = angle;
        *(float *)(joint + 0x50) = func_00194FB8(angle);
    }
}
