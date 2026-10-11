#include "common.h"

float atan2f(float, float);

float func_001954A8(float *arg0, float *arg1) {
    float angle;
    float wrapped;

    angle = atan2f(arg1[0] - arg0[0], arg1[2] - arg0[2]);
    wrapped = angle + 3.1415927f;
    wrapped = wrapped - (float)(int)(wrapped / 6.2831855f) * 6.2831855f;
    if (3.1415927f < wrapped) {
        wrapped -= 6.2831855f;
    } else if (wrapped < -3.1415927f) {
        wrapped += 6.2831855f;
    }
    return wrapped;
}
