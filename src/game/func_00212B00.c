#include "common.h"

extern int D_00446770;

typedef struct {
    char pad0[0xD0];
    float x;
    float y;
    float z;
} Target;

typedef struct {
    Target *target;
} Rec;

typedef struct {
    int active;
    char pad4[4];
    int id;
    char padC[4];
    float goal_x;
    char pad14[4];
    float goal_y;
    char pad1C[4];
    float goal_z;
    char pad24[4];
    int frames_left;
} Mover;

Rec *func_0011E1F0(int, int);
int func_0019B9F0(float, float *, int);

/* Eases a record's position toward a goal over frames_left frames, then stops. */
void func_00212B00(Mover *arg0) {
    Rec *rec;

    rec = func_0011E1F0(D_00446770, arg0->id);
    if (rec == NULL) {
        arg0->active = 0;
        return;
    }
    if (arg0->goal_x == rec->target->x && arg0->goal_y == rec->target->y &&
        arg0->goal_z == rec->target->z) {
        arg0->active = 0;
        return;
    }
    func_0019B9F0(arg0->goal_x, &rec->target->x, arg0->frames_left);
    func_0019B9F0(arg0->goal_y, &rec->target->y, arg0->frames_left);
    func_0019B9F0(arg0->goal_z, &rec->target->z, arg0->frames_left);
    if (--arg0->frames_left < 0) {
        arg0->active = 0;
    }
}
