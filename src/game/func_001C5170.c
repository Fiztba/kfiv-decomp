#include "common.h"

int func_0020E1F8(int, int, int, int, float, float);

typedef struct {
    char pad[0x1B8];
    int (*get_point)(void *, int);
} Model;

typedef struct {
    Model *model;
    char pad4[0xC];
    int flags;
} Owner;

/* Draws up to two segments through three or four model points. */
int func_001C5170(Owner *arg0, int arg1, float arg2, float arg3) {
    int p0, p1, p2, p3, r;

    if (arg0->flags & 0x10000) {
        p0 = arg0->model->get_point(arg0->model, 0);
        p1 = arg0->model->get_point(arg0->model, 1);
        p2 = arg0->model->get_point(arg0->model, 2);
        p3 = arg0->model->get_point(arg0->model, 3);
        func_0020E1F8(p0, p1, p2, arg1, arg3, arg2);
        r = *(int *)0x70000010;
        if (r == 0) {
            return func_0020E1F8(p0, p2, p3, arg1, arg3, arg2);
        }
        return r;
    }
}
