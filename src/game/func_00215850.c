#include "common.h"

/* position block at *Obj */
typedef struct {
    char pad00[0xD0];
    float x;                    /* 0xD0 */
    float y;                    /* 0xD4 */
    float z;                    /* 0xD8 */
} ObjPos;

typedef struct {
    ObjPos *pos;                /* 0x00 */
    char pad04[0x28];
    u16 unk2C;       /* 0x2C */
    char pad2E[0xAA];
    s64 flags;                 /* 0xD8 */
} Obj;

/* the command being run */
typedef struct {
    int active;                 /* 0x00 */
    int pad04;
    int target_id;              /* 0x08 */
    int pad0C;
    float dx;                   /* 0x10 */
    int pad14;
    float dy;                   /* 0x18 */
    int pad1C;
    float dz;                   /* 0x20 */
    int pad24;
    int frames_left;            /* 0x28 */
    int pad2C;
    int unk30;                  /* 0x30 */
    int pad34;
    int unk38;                  /* 0x38 */
} MoveCmd;

Obj *func_001267B0(int);
int func_00192EB0(void *, int);
float func_00194FB8(float);

/* Per frame, shift the target object's position by the command's deltas (wrapped), then count down. */
void func_00215850(MoveCmd *cmd) {
    Obj *obj;

    obj = func_001267B0(cmd->target_id);
    if (obj != NULL && (obj->flags & 0xF) == 3 && obj->unk2C != 0) {
        obj->pos->x = func_00194FB8(obj->pos->x + cmd->dx);
        obj->pos->y = func_00194FB8(obj->pos->y + cmd->dy);
        obj->pos->z = func_00194FB8(obj->pos->z + cmd->dz);
        if (cmd->unk30 != 0) {
            func_00192EB0(obj, cmd->unk38);
        }
        if (--cmd->frames_left != 0) {
            return;
        }
    }
    cmd->active = 0;
}
