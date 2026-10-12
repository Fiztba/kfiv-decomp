#include "common.h"
#include "kf_effect.h"
#include "kf_entity.h"

extern Entity *D_004467E0;

int func_001B0040(Entity *);
float func_001B0178(void *, void *);
float func_001B01B0(void *, void *);

/* Picks the four nearest entities in front of the effect, nearest first. */
void func_001A6EE8(EffectActor *actor, EffectSlot *spawn_slot) {
    PickedMotion *picked = (PickedMotion *)&actor->motion;
    Entity *entity;
    f32 distance;
    f32 height;
    int n;
    int i;
    int k;

    func_001AF928(actor, spawn_slot);
    func_001AF640(actor, spawn_slot);
    for (i = 0; i < 4; i++) {
        picked->index[i] = -1;
        picked->entity[i] = NULL;
        picked->distance[i] = 65535.0f;
    }
    n = 0;
    for (entity = D_004467E0; entity != NULL; entity = entity->next, n++) {
        if (func_001B0040(entity) != 0) {
            continue;
        }
        distance = func_001B0178(&ENTITY_MODEL(entity)->position, &actor->model->position);
        if ((float)actor->def->interval < distance) {
            continue;
        }
        height = ENTITY_MODEL(entity)->position.y - actor->model->position.y;
        if (height <= 10.0f) {
            continue;
        }
        if (func_001B01B0(&ENTITY_MODEL(entity)->position, &actor->model->position) / height > 1.0f) {
            continue;
        }
        for (i = 0; i < 4; i++) {
            if (distance < picked->distance[i]) {
                for (k = 3; k > i; k--) {
                    picked->index[k] = picked->index[k - 1];
                    picked->distance[k] = picked->distance[k - 1];
                    picked->entity[k] = picked->entity[k - 1];
                }
                picked->index[i] = n;
                picked->distance[i] = distance;
                picked->entity[i] = entity;
                break;
            }
        }
    }
}
