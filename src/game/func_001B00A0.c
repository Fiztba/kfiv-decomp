#include "common.h"

/* Entity layout with the radius field, which kf_entity.h does not have yet. */
typedef struct Obj {
    char *model;           /* 0x00 */
    char pad04[0x18];
    struct Obj *next;      /* 0x1C */
    char pad20[0x18];
    float radius;          /* 0x38 */
    float height;          /* 0x3C */
    char pad40[0x98];
    s64 flags;             /* 0xD8 */
} Obj;

extern Obj *D_004467E0;
float func_001B0178(void *, void *);
void func_00216778(float *, void *);

/* Nonzero if the point is within radius of any live entity's centre. */
int func_001B00A0(float radius, void *point) {
    float position[4] __attribute__((aligned(16)));
    Obj *obj;

    for (obj = D_004467E0; obj != NULL; obj = obj->next) {
        if (((int)(obj->flags >> 1) & 1) == 0) continue;
        if (((int)(obj->flags >> 2) & 3) > 0) continue;
        func_00216778(position, obj->model + 0xC0);
        position[1] -= obj->height * 0.5f;
        if (func_001B0178(point, position) <= radius + obj->radius) return TRUE;
    }
    return FALSE;
}
