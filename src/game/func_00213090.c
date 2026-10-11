#include "common.h"

void *func_0011E1F0(int, int);
extern int D_00446770;

typedef struct {
    char pad[0xC0];
    float x;
    float y;
    float z;
} Vec3;

typedef struct {
    Vec3 *v;
} Node;

/* Add this command's per-frame offset to the target node's position; the command ends when its step count runs out. */
void func_00213090(char *arg0) {
    Node *temp_v0;
    Vec3 *pos;
    int steps_left;

    temp_v0 = func_0011E1F0(D_00446770, *(int *)(arg0 + 0x8));
    if (temp_v0 == NULL || *(int *)(arg0 + 0x28) <= 0) {
        *(int *)arg0 = 0;
        return;
    }
    steps_left = *(int *)(arg0 + 0x28) - 1;
    pos = temp_v0->v;
    pos->x = pos->x + *(float *)(arg0 + 0x10);
    pos->y = pos->y + *(float *)(arg0 + 0x18);
    pos->z = pos->z + *(float *)(arg0 + 0x20);
    *(int *)(arg0 + 0x28) = steps_left;
    if (steps_left <= 0) {
        *(int *)arg0 = 0;
    }
}
