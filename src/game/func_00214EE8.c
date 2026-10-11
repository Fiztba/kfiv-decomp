#include "common.h"

void sceVu0RotMatrixY(float, int *, int *);
void sceVu0ApplyMatrix(float *, int *, float *);
void KF_Vector_Scale(void *, void *, float);
void func_00216C48(void *, void *, void *);
int func_00211D90(void *, double);  // match: retail converts the float argument to double at the call site (fptodp), as the definition takes float
extern int D_00431AF0[];
extern float D_00413F80[];

typedef struct {
    int unk0;
    char pad4[4];
    int unk8;
    int x;
    int pad10;
    int y;
    int pad18;
    int z;
} Target;

/* Rotates the vector at D_00413F80+0x1AC about Y, scales it, and stores the three components as ints. */
void func_00214EE8(Target *target) {
    int matrix[16];
    float vec[4];
    float out[4];

    vec[0] = D_00413F80[0x1B0 / 4];
    vec[1] = D_00413F80[0x1AC / 4];
    vec[2] = D_00413F80[0x1B4 / 4];
    vec[3] = 0.0f;
    sceVu0RotMatrixY(D_00413F80[0x14 / 4], matrix, D_00431AF0);
    sceVu0ApplyMatrix(vec, matrix, vec);
    KF_Vector_Scale(vec, vec, (float)target->unk8);
    func_00216C48(out, D_00413F80, vec);
    func_00211D90(&target->x, out[0]);
    func_00211D90(&target->y, out[1]);
    func_00211D90(&target->z, out[2]);
    target->unk0 = 0;
}
