#include "common.h"

typedef struct {
    char padC0[0xC0];
    float pos[4];
    float rot_x;
    float rot_y;
    float rot_z;
} Model;

typedef struct {
    char pad0[0x18];
    Model *model;
} Actor;

void func_00216C48(void *, void *, void *);
void func_00216778(void *, void *);
int func_0019B9F0(float, float *, int);
extern Actor *D_004469D8;
extern float D_00413F90[];
extern float D_0044719C;
extern int D_004471A4;
extern float D_004471A8;
extern int D_004471AC;
extern int D_004471B0;
extern char D_005B60E0[];
extern char D_005B60F0[];

/* Counts down a blend: steps the actor's vectors toward a target, resetting when done. */
void func_001C9EB0(void) {
    D_004471B0--;
    if (D_004471B0 > 0) {
        func_00216C48(D_004469D8->model->pos, D_004469D8->model->pos, D_005B60F0);
        func_0019B9F0(0.0f, &D_004469D8->model->rot_x, D_004471B0);
        func_0019B9F0(0.0f, &D_004469D8->model->rot_y, D_004471B0);
        func_0019B9F0(0.0f, &D_004469D8->model->rot_z, D_004471B0);
        func_0019B9F0(D_004471A8, D_00413F90, D_004471B0);
        D_0044719C = (float)D_004471B0 / (float)D_004471AC;
        return;
    }
    func_00216778(D_004469D8->model->pos, D_005B60E0);
    D_0044719C = 0.0f;
    D_00413F90[0] = D_004471A8;
    D_004471A4++;
}
