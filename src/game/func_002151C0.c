#include "common.h"

typedef struct {
    char pad00[0x2C];
    unsigned short unk2C;       /* 0x2C */
    char pad2E[0xAA];
    long flags;                 /* 0xD8 */
} Obj;

/* the command being run */
typedef struct {
    int active;                 /* 0x00 */
    int pad04;
    int target_id;              /* 0x08 */
    int pad0C;
    int frames_left;            /* 0x10 */
    int pad14;
    int unk18;                  /* 0x18 */
} MoveCmd;

Obj *func_001267B0(int);
int func_00192EB0(void *, int);

/* Each frame, run the callback on the target object until the frame count runs out. */
void func_002151C0(MoveCmd *cmd) {
    Obj *obj;

    obj = func_001267B0(cmd->target_id);
    if (obj != NULL && (obj->flags & 0xF) == 3 && obj->unk2C != 0) {
        func_00192EB0(obj, cmd->unk18);
        if (--cmd->frames_left != 0) {
            return;
        }
    }
    cmd->active = 0;
}
