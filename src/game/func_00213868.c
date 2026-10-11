#include "common.h"

extern char D_0038CD20[];
extern int D_00446770;

typedef struct {
    float x;
    float y;
    float z;
    int w;
} __attribute__((aligned(16))) Vec4;

typedef struct {
    int unk0;
    int pad4;
    int unk8;
    int padC;
    float x0;
    int pad14;
    float y0;
    int pad1C;
    float z0;
    int pad24;
    float x1;
    int pad2C;
    float y1;
    int pad34;
    float z1;
} Obj;

void func_001A1C58(int, char *, int, void *);

void func_00213868(Obj *arg0) {
    Vec4 out_a = (Vec4){ arg0->x0, arg0->y0, arg0->z0, 0 };
    Vec4 out_b = (Vec4){ arg0->x1, arg0->y1, arg0->z1, 0 };

    func_001A1C58(arg0->unk8, &out_a, &out_b, D_0038CD20 + D_00446770 * 0x60);
    arg0->unk0 = 0;
}
