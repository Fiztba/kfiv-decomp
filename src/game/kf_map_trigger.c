#include "kf_model.h"
#include "kf_game.h"
#include "kf_message.h"
#include "kf_map_object.h"
#include "kf_map.h"
#include "kf_item.h"

typedef struct {
    int phase;
    int period;
} Wave;
typedef struct {
    void *ptr;
    char pad[0x3C];
    Wave w;
} Obj;
void func_0011FBE8(void);
void func_0011FC10(void);
void ModelMatrix_Build(ModelInstance *, Vector4 *, Vector4 *, f32 *);
void ModelMatrix_BuildPartLocal(ModelInstance *, ModelPart *, ModelPart *);
void func_0010B5D0(ModelPart *);
void Matrix_Multiply(void *, void *, void *);
void sceVu0CopyMatrix(void *, void *);
void sceVu0RotMatrixX(float *, float *, float);
void sceVu0RotMatrixY(float *, float *, float);
void sceVu0RotMatrixZ(float *, float *, float);
void sceVu0TransMatrix(float *, float *, float *);
void Vector_Scale(float *, float *, float);
void func_0010E6A8(ModelInstance *, s64, s64);
void func_0010E820(ModelInstance *, s64);
void func_0010E8E0(void *, int, int, int, int);
int func_0010EA08(int, void *, int *, int *, float);
void *memset(void *, int, u32);
int rand(void);
extern GameStatus D_0038CC50;
extern void *D_00420D50[];
extern u32 D_0038CC74[];
extern f32 D_00431AF0[16];

void func_001226D0(char *arg0) {
    arg0[0x11] = 1;
}

/* Update handler of the save point (kind 20): used by the player, it asks for the save screen (GameStatus.bit5)
   and hands over its word 0x44, the message id of the area's name that the save list shows. */
void MapObject_UpdateSavePoint(MapObject *object) {
    MapObject *used;

    if (D_0038CC50.bit1 && (used = D_00420D50[0]) == object) {
        D_0038CC50.save_requested = TRUE;
        D_0038CC50.save_area = MAP_OBJECT_WORDS(used)->unk44;
    }
}

void func_00122720(char *arg0) {
    (*(int *)((char *)arg0 + 0x40)) = 0;
    (*(u8 *)((char *)arg0 + 0x11)) = 1;
}

/* Update handler: used by the player, it shows the message of its definition,
   at most every 45 frames. */
void func_00122730(MapObject *object) {
    int message;

    if (object->work[0] > 0) {
        object->work[0]--;
    }
    if (((D_0038CC74[0] >> 1) & 1) && D_00420D50[0] == object) {
        if (object->work[0] > 0) {
            return;
        }
        message = (s16)object->unk04->unk68;
        if (message == 0) {
            return;
        }
        Message_ShowNotice(0, 0, 0, 0, 0x2D, message);
        object->work[0] = 0x2D;
    }
}

void func_001227C0(void) {
    func_0011FBE8();
}

void func_001227C8(void) {
    func_0011FC10();
}

/* Start handler: closed (animation 4, step 1) or, with bit 17 set, open (animation 5, step 3). */
void func_001227D0(MapObject *object) {
    if (!(object->unk10 & 0x20000)) {
        MapObject_StartAnim(object, 4);
        MAP_OBJECT_BYTES(object)->step = 1;
    } else {
        MapObject_StartAnim(object, 5);
        MAP_OBJECT_BYTES(object)->step = 3;
    }
}

/* Update handler, step 1: used by the player, it starts turning on. */
void func_00122828(MapObject *object) {
    MapObject *used = D_00420D50[0];

    if (used == object && ((D_0038CC74[0] >> 1) & 1)) {
        used->unk10 |= 0x20000;
        MAP_OBJECT_BYTES(used)->step = 2;
    }
}

/* Update handler of a switch turning on: runs the animation, then it is on. */
void func_00122868(MapObject *object) {
    if (MODEL_CHANNEL(object->model)->param != 0) {
        MapObject_StepAnim(object);
    } else {
        MapObject_StartAnim(object, 5);
        MAP_OBJECT_BYTES(object)->step = 3;
    }
}

/* Update handler, step 3: used by the player, it starts turning off. */
void func_001228C0(MapObject *object) {
    MapObject *used = D_00420D50[0];

    if (used == object && ((D_0038CC74[0] >> 1) & 1)) {
        used->unk10 &= ~0x20000;
        MAP_OBJECT_BYTES(used)->step = 4;
    }
}

/* Update handler of a switch turning off: runs the animation, then it is off. */
void func_00122908(MapObject *object) {
    if (MODEL_CHANNEL(object->model)->param != 0) {
        MapObject_StepAnim(object);
    } else {
        MapObject_StartAnim(object, 4);
        MAP_OBJECT_BYTES(object)->step = 1;
    }
}

/* Switches the trigger on (type 1 to 2) or off (type 3 to 4) when it is at rest in the other position. */
void func_00122960(MapTrigger *trigger, int turn_on) {
    if (MAP_TRIGGER_FLAGS(trigger)->bits.type == 1 && !MAP_TRIGGER_FLAGS(trigger)->bits.flag_20000 && turn_on) {
        MAP_TRIGGER_FLAGS(trigger)->bits.flag_20000 = TRUE;
        MAP_TRIGGER_FLAGS(trigger)->bits.type = 2;
    } else if (MAP_TRIGGER_FLAGS(trigger)->bits.type == 3 && MAP_TRIGGER_FLAGS(trigger)->bits.flag_20000 && !turn_on) {
        MAP_TRIGGER_FLAGS(trigger)->bits.flag_20000 = FALSE;
        MAP_TRIGGER_FLAGS(trigger)->bits.type = 4;
    }
}

/* An angle brought back into -half_turn..half_turn. */
static inline f32 func_001229D0_wrap_angle(f32 angle, f32 half_turn) {
    angle += half_turn;
    angle -= (f32)(s32)(angle / 6.2831855f) * 6.2831855f;
    return angle - half_turn;
}

/* Rebuilds the trigger's model matrices, then turns the whole model about its second part's pivot. */
void func_001229D0(MapTrigger *trigger) {
    f32 matrix[16];
    f32 pivot_back[4];
    ModelPart *part;
    f32 *pivot;
    int part_count;
    int i;
    ModelPart *joint;
    f32 half_turn;

    ModelMatrix_Build(trigger->model, &trigger->model->position, &trigger->model->rotation, &trigger->model->unkE0);
    part_count = trigger->model->part_count;
    part = trigger->model->parts;
    for (i = 0; i < part_count; i++) {
        ModelMatrix_BuildPartLocal(trigger->model, part, part);
        part++;
    }
    part = trigger->model->parts;
    if (trigger->model->unk100 & 1) {
        for (i = 0; i < part_count; i++) {
            func_0010B5D0(part);
            part++;
        }
        part = trigger->model->parts;
    }
    joint = part;
    half_turn = 3.1415927f;
    sceVu0CopyMatrix(matrix, D_00431AF0);
    // match: an empty loop here (a debug macro compiled out?) keeps the scheduler from moving anything across
    // this point, which is what leaves the half_turn load in front of the call above
    do { } while (0);
    pivot = joint[1].unk40;
    Vector_Scale(pivot_back, pivot, -1.0f);
    joint++;
    sceVu0TransMatrix(matrix, matrix, pivot_back);
    sceVu0RotMatrixX(matrix, matrix, func_001229D0_wrap_angle(joint->unk50, half_turn));
    sceVu0RotMatrixZ(matrix, matrix, func_001229D0_wrap_angle(joint->unk58, half_turn));
    sceVu0RotMatrixY(matrix, matrix, func_001229D0_wrap_angle(joint->unk54, half_turn));
    sceVu0TransMatrix(matrix, matrix, pivot);
    Matrix_Multiply(trigger->model->unk80, trigger->model->unk40, matrix);
    trigger->model->unk1B4(trigger->model);
}

/* Starts this kind of trigger: at rest in the position its flag gives. */
void func_00122BE8(MapTrigger *trigger) {
    MapTriggerShotKind122BE8 *shot = (MapTriggerShotKind122BE8 *)&trigger->shot;

    func_0010E6A8(trigger->model, 0x40, 0x40);
    func_0010E820(trigger->model, 0x44);
    shot->unk00[0] = 0.0f;
    shot->unk00[1] = -700.0f;
    shot->unk00[2] = 0.0f;
    shot->unk00[3] = 0.0f;
    shot->unk10 = 0.0f;
    if (!(MAP_TRIGGER_FLAGS(trigger)->word & MAP_TRIGGER_FLAG_20000)) {
        trigger->type = 1;
        func_0010E8E0(trigger->model, -1, -1, -1, 0);
    } else {
        trigger->type = 3;
        func_0010E8E0(trigger->model, -1, -1, -1, 0x80);
    }
}

void func_00122CA8(void) {
}

/* Advances the float at +0x50 toward 100000, then calls func_0010EA08; on a zero result sets state 3 and clears the float. */
void func_00122CB0(char *state_block) {
    int buf_a[4];
    int buf_b[4];
    float *timer; // timer[4] is the float at +0x50

    timer = (float *)(state_block + 0x40);
    memset(buf_a, 0, 0x10);
    buf_a[3] = 0x80;
    memset(buf_b, 0, 0x10);
    buf_b[3] = 8;
    if (timer[4] < 100000.0f) {
        timer[4] += 6.6666f;
    }
    if (func_0010EA08(*(int *)state_block, timer, buf_b, buf_a, timer[4]) == 0) {
        state_block[0x11] = 3;
        timer[4] = 0.0f;
    }
}

void func_00122D60(void) {
}

/* Advances the float at +0x50 toward 2000, then calls func_0010EA08; on a zero result sets state 1 and clears the float. */
void func_00122D68(char *actor) {
    int buf_a[4];
    int buf_b[4];
    float *timer;

    timer = (float *)(actor + 0x40);
    memset(buf_a, 0, 0x10);
    memset(buf_b, 0, 0x10);
    buf_b[3] = -8;
    if (timer[4] < 2000.0f) {
        timer[4] += 4.0f;
    }
    if (func_0010EA08(*(int *)actor, timer, buf_b, buf_a, timer[4]) == 0) {
        actor[0x11] = 1;
        timer[4] = 0.0f;
    }
}

/* Switches the trigger on (type 1 to 2) or off (type 3 to 4) when it is at rest in the other position. */
void func_00122E18(MapTrigger *trigger, int turn_on) {
    if (MAP_TRIGGER_FLAGS(trigger)->bits.type == 1 && !MAP_TRIGGER_FLAGS(trigger)->bits.flag_20000 && turn_on) {
        MAP_TRIGGER_FLAGS(trigger)->bits.flag_20000 = TRUE;
        MAP_TRIGGER_FLAGS(trigger)->bits.type = 2;
    } else if (MAP_TRIGGER_FLAGS(trigger)->bits.type == 3 && MAP_TRIGGER_FLAGS(trigger)->bits.flag_20000 && !turn_on) {
        MAP_TRIGGER_FLAGS(trigger)->bits.flag_20000 = FALSE;
        MAP_TRIGGER_FLAGS(trigger)->bits.type = 4;
    }
}

/* Starts this kind of trigger: a random period and a random phase within it. */
void func_00122E88(MapTrigger *trigger) {
    MapTriggerShotKind122E88 *shot = (MapTriggerShotKind122E88 *)&trigger->shot;
    ModelInstance *model = trigger->model;

    model->unk102 |= 0x200;
    model->unk145 = 1;
    trigger->model->unk146 = 0;
    /* 4.656613e-10f is 1 / 2^31: rand() scaled to 0..1 */
    shot->period = (int)((float)rand() * 61.0f * 4.656613e-10f) + 0x78;
    shot->phase = (int)((float)(shot->period + 1) * (float)rand() * 4.656613e-10f);
    trigger->type = 1;
}

int func_00122F48(Obj *arg0) {
    Wave *w;
    int phase;
    int period;
    float f;
    int v;

    w = &arg0->w;
    phase = (w->phase + 1) % w->period;
    arg0->w.phase = phase;
    period = w->period;
    if (phase < period / 2) {
        f = (float)phase / (float)period * 0.5f;
    } else {
        f = (float)(period - phase) / (float)period * 0.5f;
    }
    v = (int)(f * 128.0f);
    *(s16 *)((char *)arg0->ptr + 0x146) = v;
    return v;
}

/* Shows "... Key used" when the item a door or chest needed is one of the keys. */
void MapObject_ShowKeyUsed(int item) {
    if (item >= ITEM_KEY_FIRST && item <= ITEM_KEY_LAST) {
        Message_ShowNotice(0, 0, 0, 0, 0x2D, item + (MSG_KEY_USED_FIRST - ITEM_KEY_FIRST));
    }
}
