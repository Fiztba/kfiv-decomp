#include "common.h"
#include "kf_effect.h"

int func_001A6BF8(EffectActor *effect, float *position, AimMotion *motion);
void func_00216778(void *, void *);
void KF_Vector_Subtract(void *, void *, void *);
float func_001B0178(void *, void *);
void sceVu0AddVector(void *, void *, void *);

/* Steps an effect that flies toward its target and ends its flight when close. */
void func_001A6C98(EffectActor *actor) {
    AimMotion *motion;
    LandedFlagMotion *target_motion;
    f32 distance;
    s8 aimed;
    Vector4 offset;

    motion = (AimMotion *)&actor->motion;
    target_motion = (LandedFlagMotion *)&actor->target->motion;
    if (motion->hit == 1) {
        func_001A2A18(actor);
        return;
    }
    func_001AEC48(actor);
    func_001AED58(actor);
    func_001AF0B0(actor);
    if (motion->state == 0 && target_motion->landed != 0) {
        motion->state = 1;
        if (func_001A6BF8(actor, &actor->target->model->position.x, motion) == 0 &&
            func_001A6BF8(actor, &actor->model->position.x, motion) == 0) {
            func_00216778(&motion->target_x, &actor->target->model->position);
            actor->frame = actor->def->keyframe_end - 4;
        }
    }
    if (actor->def->max_frames > actor->frame || actor->def->max_frames == 0) {
        distance = func_001B0178(&actor->model->position, &motion->target_x);
        if (motion->state == 0) {
            KF_Vector_Subtract(&offset, &actor->target->model->position, &actor->model->position);
            motion->speed = 3000.0f / distance * 8.0f;
            if (motion->speed < 8.0f) {
                motion->speed = 8.0f;
            }
        } else {
            KF_Vector_Subtract(&offset, &motion->target_x, &actor->model->position);
            motion->speed = 65535.0f;
        }
        if (actor->frame >= 0xD) {
            func_001AFC88(&motion->velocity, &offset, actor->def->speed, motion->speed);
        }
        sceVu0AddVector(&actor->model->position, &actor->model->position, motion);
        if (motion->state == 1 && (aimed = motion->flag25) == motion->state && distance < 50.0f) {
            func_001A1E28(actor->def->end_effect, &actor->model->position, &actor->model->rotation, actor->owner_entity, actor->effect_param, actor->owner);
            motion->hit = aimed;
        }
    }
    actor->frame += 1;
}
