#include "common.h"
#include "kf_effect.h"

int func_001B4F90(void *);
int func_001C0E40(float, void *);
void func_001AF5B0(void *, void *);
void func_00216778(void *, void *);
void sceVu0AddVector(void *, void *, void *);

/* Falls under gravity, capped at a top speed, and spawns its end effects when it lands. */
void func_001A5348(EffectActor *actor) {
    char unused[0x50]; /* unused, but retail reserves the 0x50 bytes */
    Vector4 landing;
    Vector4 *motion = &actor->motion.velocity;
    int hit;

    func_001AEC48(actor);
    func_001AED58(actor);
    func_001AF0B0(actor);
    if (actor->frame < actor->def->max_frames || actor->def->max_frames == 0) {
        motion->y += actor->def->gravity;
        if (motion->y > 45.0f) {
            motion->y = 45.0f;
        }
        sceVu0AddVector(&actor->model->position, &actor->model->position, motion);
        func_001AF5B0(&actor->model->rotation, motion);
    }
    hit = func_001B4F90(actor);
    if (hit & 8) {
        if (*(int *)0x70000018 == 3 || *(int *)0x70000018 == 5) {
            if (*(int *)0x70000018 == 5) {
                func_001A1E28(0x16, &actor->model->position, &actor->model->rotation, actor->owner_entity, actor->effect_param, actor->owner);
            }
            func_001A1E28(0x14, &actor->model->position, &actor->model->rotation, actor->owner_entity, actor->effect_param, actor->owner);
        } else {
            func_00216778(&landing, &actor->model->position);
            landing.y -= actor->def->unkDC;
            if (func_001C0E40(actor->def->unkDC + actor->def->unkDC, &landing) == 1) {
                actor->model->position.y = *(float *)0x70000004;
                func_001A1E28(actor->def->end_effect, &actor->model->position, &actor->model->rotation, actor->owner_entity, actor->effect_param, actor->owner);
            }
        }
        func_001A2A18(actor);
    } else if (hit != 0) {
        if (*(int *)0x70000018 == 3 || *(int *)0x70000018 == 5) {
            if (*(int *)0x70000018 == 5) {
                func_001A1E28(0x16, &actor->model->position, &actor->model->rotation, actor->owner_entity, actor->effect_param, actor->owner);
            }
            func_001A1E28(0x14, &actor->model->position, &actor->model->rotation, actor->owner_entity, actor->effect_param, actor->owner);
        } else {
            func_001A1E28(actor->def->radius_half, &actor->model->position, &actor->model->rotation, actor->owner_entity, actor->effect_param, actor->owner);
        }
        func_001A2A18(actor);
    }
    actor->frame++;
}
