#include "kf_map_object.h"
#include "kf_model.h"

typedef struct {
    char pad[0x24];
    u32 b0 : 1;
    u32 b1 : 1;
} A;
typedef struct {
    char pad[0x50];
    void *cur;
} B;
void func_001207D0(void *);
void func_00120868(void *);
extern u32 D_0038CC74[];
extern void *D_00420D50[];
extern A D_0038CC50;
extern B D_00420D00;

/* Start handler: animation 4, step 1. */
void func_00120668(MapObject *object) {
    MapObject_StartAnim(object, 4);
    MAP_OBJECT_BYTES(object)->step = 1;
}

void func_00120698(char *arg0) {
    if ((D_0038CC74[0] >> 1) & 1) {
        if (D_00420D50[0] == arg0) {
            arg0[0x11] = 2;
            *(int *)(arg0 + 0x10) = (*(int *)(arg0 + 0x10) & 0xFFFDFFFF) | ((((*(int *)(arg0 + 0x10)) >> 17) ^ 1) & 1) << 17;
        }
    }
}

/* Step handler: runs the animation; when it ends, starts animation 5, or with the
   channel index set animation 4 at step 1. */
void func_001206F0(MapObject *object) {
    ModelChannel *channel = MODEL_CHANNEL(object->model);

    if (channel->index == 0) {
        if (channel->param != 0) {
            MapObject_StepAnim(object);
        } else {
            MapObject_StartAnim(object, 5);
        }
    } else {
        if (channel->param == 0) {
            MapObject_StartAnim(object, 4);
            MAP_OBJECT_BYTES(object)->step = 1;
        } else {
            MapObject_StepAnim(object);
        }
    }
}

/* Start handler: closed (animation 4, step 1) or, with bit 17 set, open (animation 5, step 3). */
void func_00120778(MapObject *object) {
    if (!(object->unk10 & 0x20000)) {
        MapObject_StartAnim(object, 4);
        MAP_OBJECT_BYTES(object)->step = 1;
    } else {
        MapObject_StartAnim(object, 5);
        MAP_OBJECT_BYTES(object)->step = 3;
    }
}

/* Update handler of a switch that is off: used by the player, it starts turning on. */
void func_001207D0(void *arg) {
    MapObject *object;

    if (((D_0038CC74[0] >> 1) & 1) && (object = D_00420D50[0]) == arg) {
        MAP_OBJECT_BYTES(object)->step = 2;
        object->unk10 |= 0x20000;
    }
}

/* Update handler of a switch turning on: runs the animation, then it is on. */
void func_00120810(MapObject *object) {
    if (MODEL_CHANNEL(object->model)->param != 0) {
        MapObject_StepAnim(object);
    } else {
        MapObject_StartAnim(object, 5);
        MAP_OBJECT_BYTES(object)->step = 3;
    }
}

/* Update handler of a switch that is on: used by the player, it starts turning off. */
void func_00120868(void *arg) {
    MapObject *object;

    if (((D_0038CC74[0] >> 1) & 1) && (object = D_00420D50[0]) == arg) {
        MAP_OBJECT_BYTES(object)->step = 4;
        object->unk10 &= ~0x20000;
    }
}

/* Update handler of a switch turning off: runs the animation, then it is off. */
void func_001208B0(MapObject *object) {
    if (MODEL_CHANNEL(object->model)->param != 0) {
        MapObject_StepAnim(object);
    } else {
        MapObject_StartAnim(object, 4);
        MAP_OBJECT_BYTES(object)->step = 1;
    }
}

void func_00120908(char *arg0, int arg1) {
    void *saved;
    int bit;

    if ((*(u32 *)(arg0 + 0x10) & 0x2FF00) == 0x100 && arg1 != 0) {
        saved = D_00420D00.cur;
        bit = D_0038CC50.b1;
        D_0038CC50.b1 = 1;
        D_00420D00.cur = arg0;
        func_001207D0(arg0);
        D_00420D00.cur = saved;
        D_0038CC50.b1 = bit;
    } else if ((*(u32 *)(arg0 + 0x10) & 0x2FF00) == 0x20300 && arg1 == 0) {
        saved = D_00420D00.cur;
        bit = D_0038CC50.b1;
        D_0038CC50.b1 = 1;
        D_00420D00.cur = arg0;
        func_00120868(arg0);
        D_00420D00.cur = saved;
        D_0038CC50.b1 = bit;
    }
}
