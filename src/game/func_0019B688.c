#include "common.h"

void KF_Vector_Subtract(float *dst, float *a, float *b);

/* Cross product of (p2 - p1) and (p3 - p2), written to out. */
void func_0019B688(float *out, float *p1, float *p2, float *p3) {
    float d01[4];
    float d12[4];

    KF_Vector_Subtract(d01, p2, p1);
    KF_Vector_Subtract(d12, p3, p2);
    out[0] = d01[1] * d12[2] - d01[2] * d12[1];
    out[1] = d01[2] * d12[0] - d01[0] * d12[2];
    out[2] = d01[0] * d12[1] - d01[1] * d12[0];
}
