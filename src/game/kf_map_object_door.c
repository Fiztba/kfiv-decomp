#include "kf_map_object.h"
#include "kf_model.h"
#include "kf_message.h"

typedef struct {
    char pad[0xC0];
    float x;
    char pad2[4];
    float y;
} Pos;
typedef struct {
    char pad[0x46];
    s16 s46;
} Dev;
typedef struct {
    char pad[0x1C];
    int count;
} Sub;
typedef struct {
    Pos *p00;
    char pad04[4];
    Dev *d08;
    char pad0C[4];
    int flags10;
    float f14;
    char pad18[0x28];
    Sub sub40;
} Actor;
void Vector_Copy(void *, void *);
void func_0011F498(MapObject *);
void MapObject_ShowKeyUsed(int);
void func_0019D490(s32, s32, f32 *, f32);
void Vector_Subtract(void *, void *, void *);
float sinf(float);
float cosf(float);
float sqrtf(float);
void Vector_Add(void *, void *, void *);
void ModelMatrix_Build(ModelInstance *, Vector4 *, Vector4 *, f32 *);
void ModelMatrix_BuildPartLocal(ModelInstance *, ModelPart *, ModelPart *);
void func_0010B5D0(ModelPart *);
void sceVu0CopyMatrix(void *, void *);
extern void *D_00420D50[];
extern u32 D_0038CC74[];
extern u8 item_counts[];
extern float D_00413F80[];

/* Start handler of the door-like kinds: closed (animation 4) or already open
   (animation 5). Kind 6 remembers where its second part sits and, when it starts
   open, is run until it gets there. */
void func_0011F238(MapObject *object) {
    MapObjectWork *work = MAP_OBJECT_WORK(object);
    ModelPart *part;

    if (object->unk04->kind == 6) {
        MapObject_StartAnim(object, 4);
        MAP_OBJECT_BYTES(object)->step = 1;
        Vector_Copy(work, object->model->parts[1].unk40);
        work->timer = 0;
        part = object->model->parts;
        work->unk10 = part[1].unk40[0];
        work->unk14 = part[1].unk40[1];
        work->unk18 = part[1].unk40[2];
        if (MAP_OBJECT_FLAGS(object) & 0x20000) {
            MAP_OBJECT_BYTES(object)->step = 2;
            do {
                func_0011F498(object);
            } while (MAP_OBJECT_BYTES(object)->step != 3);
        }
    } else {
        if (!(object->unk10 & 0x20000)) {
            MapObject_StartAnim(object, 4);
            MAP_OBJECT_BYTES(object)->step = 1;
        } else {
            MapObject_StartAnim(object, 5);
            MAP_OBJECT_BYTES(object)->step = 3;
        }
        MAP_OBJECT_UNK60_BITS(object)->bit0 = FALSE;
    }
}

/* Update handler of a closed door (kinds 1, 2, 6 and 0x11): when the player uses it, it opens if it needs no
   item or the player holds the item (the key), else its name ("Jail Door", ...) or "Locked" is shown. */
void MapObject_UpdateClosedDoor(MapObject *object) {
    MapObjectWork *work = MAP_OBJECT_WORK(object);
    s16 item;
    f32 range;
    int message;

    if (work->timer > 0) {
        work->timer--;
    }
    if (D_00420D50[0] == object && ((D_0038CC74[0] >> 1) & 1)) {
        item = object->unk08->unk44;
        if (item != 0 && !(object->unk10 & 0x40000)) {
            if (item_counts[item] != 0) {
                MapObject_ShowKeyUsed(item);
                range = 800.0f;
                if (object->unk04->unk70 > 0.0f) {
                    range = object->unk04->unk70;
                }
                // match: it returns a value
                ((int (*)(s32, s32, f32 *, f32))func_0019D490)(0x2E, 0, &object->model->position.x, range);
                object->unk10 |= 0x40000;
            } else {
                if (work->timer > 0) {
                    return;
                }
                message = (s16)object->unk04->unk68;
                if (message == 0) {
                    message = MSG_LOCKED;
                }
                Message_ShowNotice(0, 0, 0, 0, 0x2D, message);
                work->timer = 0x2D;
                return;
            }
        }
        object->unk10 |= 0x20000;
        MAP_OBJECT_BYTES(object)->step = 2;
        MAP_OBJECT_UNK60_BITS(object)->bit0 = TRUE;
    }
}

/* Update handler of an opening door-like object: runs the animation (kind 6
   moves with its second part; kind 2 clears unk60 bit 0 once both pairs of its
   points are more than 225 apart); at its end the object is open. */
void func_0011F498(MapObject *object) {
    MapObjectWork *work = MAP_OBJECT_WORK(object);
    Vector4 delta;
    Vector4 offset;
    f32 sine;
    f32 cosine;
    f32 *point_a;
    f32 *point_b;
    f32 *point_c;
    f32 *point_d;
    f32 gap_ad;
    f32 gap_bc;
    f32 delta_x;
    f32 delta_z;
    u8 kind;

    if (work->timer > 0) {
        work->timer--;
    }
    if (MODEL_CHANNEL(object->model)->param != 0) {
        ((int (*)(char *))MapObject_StepAnim)((char *)object); // match: it returns a value
        kind = object->unk04->kind;
        if (kind == 6) {
            Vector_Subtract(&delta, object->model->parts[1].unk40, work);
            sine = sinf(-object->model->rotation.y);
            cosine = cosf(-object->model->rotation.y);
            offset.y = delta.y;
            offset.x = delta.x * cosine - delta.z * sine;
            offset.z = delta.x * sine + delta.z * cosine;
            Vector_Add(&object->model->position, &object->model->position, &offset);
            Vector_Copy(work, object->model->parts[1].unk40);
        } else if (kind == 2) {
            if (object->unk60 & 1) {
                object->model->unk1B4(object->model);
                point_a = (f32 *)object->model->get_point(object->model, 2);
                point_b = (f32 *)object->model->get_point(object->model, 3);
                point_c = (f32 *)object->model->get_point(object->model, 4);
                point_d = (f32 *)object->model->get_point(object->model, 5);
                delta_x = point_a[0] - point_d[0];
                delta_z = point_a[2] - point_d[2];
                gap_ad = sqrtf(delta_x * delta_x + delta_z * delta_z);
                delta_x = point_b[0] - point_c[0];
                delta_z = point_b[2] - point_c[2];
                gap_bc = sqrtf(delta_x * delta_x + delta_z * delta_z);
                if (gap_ad > 225.0f && gap_bc > 225.0f) {
                    MAP_OBJECT_UNK60_BITS(object)->bit0 = FALSE;
                }
            }
        }
    } else {
        MapObject_StartAnim(object, 5);
        MAP_OBJECT_BYTES(object)->step = 3;
    }
}

void func_0011F708(Actor *a) {
    Pos *p;
    Sub *s;
    float *g;
    float dx;
    float dy;
    float dist;

    s = &a->sub40;
    if (s->count > 0) {
        s->count = s->count - 1;
    }
    if (a->d08->s46 == 0) {
        p = a->p00;
        g = D_00413F80;
        dx = p->x - g[0];
        dy = p->y - g[2];
        dist = sqrtf(dx * dx + dy * dy);
        if (!(dist < a->f14 + 100.0f)) {
            a->flags10 &= 0xFFFDFFFF;
            ((char *)a)[0x11] = 4;
        }
    }
}

/* Update handler of a closing door-like object: runs the animation (kind 6 moves
   with its second part); at its end the object is closed again. */
void func_0011F7E0(MapObject *object) {
    MapObjectWork *work = MAP_OBJECT_WORK(object);
    Vector4 delta;
    Vector4 offset;
    f32 sine;
    f32 cosine;

    if (work->timer > 0) {
        work->timer--;
    }
    if (MODEL_CHANNEL(object->model)->param != 0) {
        ((int (*)(char *))MapObject_StepAnim)((char *)object); // match: it returns a value
        if (object->unk04->kind == 6) {
            Vector_Subtract(&delta, object->model->parts[1].unk40, work);
            sine = sinf(-object->model->rotation.y);
            cosine = cosf(-object->model->rotation.y);
            offset.y = delta.y;
            offset.x = delta.x * cosine - delta.z * sine;
            offset.z = delta.x * sine + delta.z * cosine;
            Vector_Add(&object->model->position, &object->model->position, &offset);
            Vector_Copy(work, object->model->parts[1].unk40);
        }
    } else {
        MapObject_StartAnim(object, 4);
        MAP_OBJECT_BYTES(object)->step = 1;
        Vector_Copy(&object->model->position, object->unk08);
    }
}

/* Opens a closed door-like object (step 1 to 2) or closes an open one (3 to 4). */
void func_0011F910(MapObject *object, int open) {
    if ((object->unk10 & 0x2FF00) == 0x100 && open) {
        object->unk10 |= 0x20000;
        MAP_OBJECT_BYTES(object)->step = 2;
    } else if ((object->unk10 & 0x2FF00) == 0x20300 && !open) {
        object->unk10 &= ~0x20000;
        MAP_OBJECT_BYTES(object)->step = 4;
    }
}

/* Rebuilds the model matrices of a kind 6 object with its second part put where
   it was when the object started, then puts the part back. */
void func_0011F980(MapObject *object) {
    Vector4 saved;
    int i;
    ModelPart *part;
    int part_count;

    // match: it returns a value
    ((int (*)(ModelInstance *, Vector4 *, Vector4 *, f32 *))ModelMatrix_Build)(object->model, &object->model->position, &object->model->rotation, &object->model->unkE0);
    Vector_Copy(&saved, object->model->parts[1].unk40);
    Vector_Copy(object->model->parts[1].unk40, &MAP_OBJECT_WORK(object)->unk10);
    object->model->parts[1].unk40[3] = 1.0f;
    part_count = object->model->part_count;
    part = object->model->parts;
    for (i = 0; i < part_count; i++) {
        ModelMatrix_BuildPartLocal(object->model, part, part);
        part++;
    }
    Vector_Copy(object->model->parts[1].unk40, &saved);
    if (object->model->unk100 & 1) {
        part = object->model->parts;
        for (i = 0; i < part_count; i++) {
            func_0010B5D0(part);
            part++;
        }
    }
    sceVu0CopyMatrix(object->model->unk80, object->model->unk40);
    object->model->unk1B4(object->model);
}

void func_0011FAA0(char *arg0) {
    arg0[0x11] = 1;
}
