#include "common.h"
#include "kf_effect.h"

void func_00216C48(void *, void *, void *);
void *memset(void *, int, u32);

/* Swings its model's heading back and forth, then moves it by the velocity. */
void func_001AB670(EffectActor *actor) {
    Vector4 offset;
    SwingMotion *motion;
    f32 heading;
    char unused[0x50]; /* unused, but retail reserves the frame */

    memset(&offset, 0, sizeof(offset));
    motion = (SwingMotion *)&actor->motion;
    offset.z = 1.0f;
    func_001AEC48(actor);
    func_001AED58(actor);
    func_001AF0B0(actor);
    heading = actor->model->rotation.x + motion->angle;
    heading -= (f32)(s32)(heading / 6.2831855f) * 6.2831855f;
    if (heading > 3.1415927f) {
        heading -= 6.2831855f;
    } else if (heading < -3.1415927f) {
        heading += 6.2831855f;
    }
    actor->model->rotation.x = heading;
    motion->phase = actor->def->unkDC;
    if (actor->frame < actor->def->radius_half) {
        motion->phase *= 0.3f;
    }
    if ((s8)motion->counter == 0) {
        if (actor->def->unkE0 < actor->model->rotation.x) {
            motion->angle -= motion->phase;
        } else {
            motion->angle += motion->phase;
            if (motion->angle > 0.0f) {
                motion->counter = 1;
                motion->angle = 0.0f;
                motion->phase = -motion->phase;
            }
        }
    } else if (-actor->def->unkE0 < actor->model->rotation.x) {
        motion->angle -= motion->phase;
        if (motion->angle < 0.0f) {
            motion->counter = 0;
            motion->angle = 0.0f;
            motion->phase = -motion->phase;
        }
    } else {
        motion->angle += motion->phase;
    }
    if (actor->def->radius_half < actor->frame) {
        motion->phase_step += motion->spin_per_frame;
        motion->velocity.y += motion->phase_step * motion->phase_step;
    }
    func_00216C48(&actor->model->position, motion, &offset);
    actor->frame++;
}
