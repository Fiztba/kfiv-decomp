#include "common.h"

int func_0010EA08(int, void *, int *, int *, float);
void *memset(void *, int, unsigned int);

/* Advances the float at +0x50 toward 100000, then calls func_0010EA08; on a zero result sets state 3 and clears the float. */
void func_00122CB0(char *arg0) {
    int buf_a[4];
    int buf_b[4];
    float *timer;

    timer = (float *)(arg0 + 0x40);
    memset(buf_a, 0, 0x10);
    buf_a[3] = 0x80;
    memset(buf_b, 0, 0x10);
    buf_b[3] = 8;
    if (timer[4] < 100000.0f) {
        timer[4] = timer[4] + 6.6666f;
    }
    if (func_0010EA08(*(int *)arg0, timer, buf_b, buf_a, timer[4]) == 0) {
        arg0[0x11] = 3;
        timer[4] = 0.0f;
    }
}
