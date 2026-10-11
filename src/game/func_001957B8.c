#include "common.h"

/* Wraps the difference b - a into [-PI, PI). */
float func_001957B8(float a, float b) {
    float diff = b - a;

    diff -= (int)(diff / 6.2831855f) * 6.2831855f;
    if (diff > 3.1415927f) {
        diff -= 6.2831855f;
    } else if (diff < -3.1415927f) {
        diff += 6.2831855f;
    }
    return diff;
}
