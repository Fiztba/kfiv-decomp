#include "common.h"
#include "kf_effect.h"
#include "kf_entity.h"

extern Entity *D_004467E0;
void KF_Vector_Subtract(Vector4 *, void *, void *);
void func_001AF5B0(void *, void *);
int func_001B0040(Entity *);
float func_001B0178(void *, void *);
f32 func_001B0950(f32);

/* Picks the live entity that scores lowest for an effect: close enough, and within the definition's angle limits of the effect's aim. */
Entity *func_001AFD08(EffectActor *actor, Vector4 *position, Vector4 *rotation) {
    Entity *best;
    Entity *entity;
    f32 best_score;
    f32 distance;
    f32 score;
    f32 yaw;
    f32 pitch;
    Vector4 angles;
    Vector4 offset;

    best = NULL;
    best_score = 65535.0f;
    for (entity = D_004467E0; entity != NULL; entity = entity->next) {
        if (func_001B0040(entity) != 0) {
            continue;
        }
        distance = func_001B0178(&entity->model->position, position);
        if ((f32)actor->def->interval < distance) {
            continue;
        }
        KF_Vector_Subtract(&offset, &entity->model->position, position);
        offset.y -= entity->height * 0.5f;
        func_001AF5B0(&angles, &offset);
        yaw = angles.x - rotation->x;
        yaw -= (f32)(int)(yaw / 6.2831855f) * 6.2831855f;
        if (3.1415927f < yaw) {
            yaw -= 6.2831855f;
        } else if (yaw < -3.1415927f) {
            yaw += 6.2831855f;
        }
        angles.x = yaw;
        pitch = angles.y - rotation->y;
        pitch -= (f32)(int)(pitch / 6.2831855f) * 6.2831855f;
        if (3.1415927f < pitch) {
            pitch -= 6.2831855f;
        } else if (pitch < -3.1415927f) {
            pitch += 6.2831855f;
        }
        angles.y = pitch;
        angles.x = func_001B0950(angles.x);
        angles.y = func_001B0950(angles.y);
        if (actor->def->unkE4 <= angles.x || actor->def->unkE8 <= angles.y) {
            continue;
        }
        score = distance * (angles.x + 1.0f) * (angles.y + 1.0f);
        if (score < 0.0f) {
            score = -score;
        }
        if (score < best_score) {
            best_score = score;
            best = entity;
        }
    }
    return best;
}
