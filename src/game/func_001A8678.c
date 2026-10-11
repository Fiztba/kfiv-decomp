#include "common.h"

void sceVu0RotMatrixX(float, int *, int *);
void sceVu0RotMatrixY(float, int *, int *);
void sceVu0ApplyMatrix(float *, int *, float *);
extern int D_00431AF0[];

void func_001AEC48(char *);
void func_001AED58(char *);
void func_001AF0B0(char *);
void func_001AF5B0(void *, void *);
void func_00216778(void *, void *);

void func_001A8678(char *actor) {
    int matrix[16];
    float direction[4];
    float angles[4];
    char *velocity;

    velocity = actor + 0x10;
    func_001AEC48(actor);
    func_001AED58(actor);
    func_001AF0B0(actor);
    direction[0] = direction[2] = direction[3] = 0.0f;
    direction[1] = 1.0f;
    func_001AF5B0(angles, *(char **)(actor + 0x60) + 0x10);
    sceVu0RotMatrixX(angles[0], matrix, D_00431AF0);
    sceVu0RotMatrixY(angles[1], matrix, matrix);
    sceVu0ApplyMatrix(direction, matrix, direction);
    func_001AF5B0(*(char **)(actor + 0x50) + 0xD0, direction);
    func_00216778(*(char **)(actor + 0x50) + 0xC0, velocity);
    func_00216778(velocity, *(char **)(*(char **)(actor + 0x60) + 0x50) + 0xC0);
    *(u16 *)(actor + 0x4C) += 1;
}
