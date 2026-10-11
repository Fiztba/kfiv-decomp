#include "common.h"

double sqrt(double);
int func_00211D90(void *, double);  // match: retail converts the float argument to double at the call site (fptodp), as the definition takes float

void func_00215FE0(char *arg0) {
    float dx;
    float dy;
    float dz;
    float s;
    float len;

    dx = *(float *)(arg0 + 0x8) - *(float *)(arg0 + 0x20);
    dy = *(float *)(arg0 + 0x10) - *(float *)(arg0 + 0x28);
    dz = *(float *)(arg0 + 0x18) - *(float *)(arg0 + 0x30);
    s = dx * dx + dy * dy + dz * dz;
    len = sqrt(s);
    func_00211D90(arg0 + 0x34, len);
    *(int *)arg0 = 0;
}
