#include "common.h"

extern int D_004469E8;
extern int D_004471C0;
extern int D_00446704;
extern int (*const D_0043F670[])(int *, int *);
extern int D_00420940[];

/* Runs the handler for the current step with a packed argument block, then advances the step. */
int func_001CD020(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    int args[7];
    int advance;

    if (D_004469E8 == 0) {
        D_004471C0 = arg3;
    }
    args[0] = arg0;
    args[1] = arg1;
    args[2] = arg2;
    args[3] = D_004471C0;
    args[4] = arg4;
    args[5] = arg5;
    args[6] = arg6;
    advance = D_0043F670[D_004469E8](args, D_00420940);
    D_004471C0 = args[3];
    D_004469E8 += advance;
    if (D_004469E8 == 6) {
        D_004469E8 = 0;
    }
    if (D_004469E8 < 0) {
        D_004469E8 = 0;
        D_00446704++;
    }
    if (D_004469E8 == 0) {
        return D_00420940[5];
    }
    return -3;
}
