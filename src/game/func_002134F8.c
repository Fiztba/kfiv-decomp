#include "common.h"

extern char D_0038CC50[];
extern float D_00413F80[];
extern float D_00413F90[];

int func_0019B9F0(float, float *, int);

typedef struct {
    int active;                 /* 0x00 */
    int pad04;
    float f8;                   /* 0x08 */
    int pad0C;
    float f10;                  /* 0x10 */
    int pad14;
    int remaining;              /* 0x18 */
} Actor;

/* Eases two of the actor's floats toward the shared target each frame until the count runs out. */
void func_002134F8(Actor *arg0) {
    if (D_0038CC50[0] != 0 || (arg0->f8 == D_00413F80[4] && arg0->f10 == D_00413F80[5])) {
        arg0->active = 0;
    } else {
        func_0019B9F0(arg0->f8, D_00413F90, arg0->remaining);
        func_0019B9F0(arg0->f10, &D_00413F90[1], arg0->remaining);
        if (--arg0->remaining == 0) {
            arg0->active = 0;
        }
    }
}
