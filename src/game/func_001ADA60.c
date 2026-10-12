#include "common.h"
#include "kf_effect.h"
#include "kf_player.h"

extern PlayerState D_00413F80;
extern f32 D_00431AF0[16];
int rand(void);
void func_001A2A18(void *);
void func_001C1430(void *, void *, f32);
void func_00216C48(void *, void *, void *);
void sceVu0RotMatrixY(float *, float *, float);
void sceVu0ApplyMatrix(float *, float *, float *);

/* Starts the effect at a random point around the player, then probes down for the ground; ends it if there is none. */
void func_001ADA60(EffectActor *actor) {
    Vector4 offset;
    f32 matrix[16];
    EffectMotion *motion;

    motion = &actor->motion;
    sceVu0RotMatrixY(matrix, D_00431AF0, D_00413F80.rotation.y);
    sceVu0ApplyMatrix(&offset.x, matrix, actor->def->offset_base);
    func_00216C48(&actor->model->position, &D_00413F80, &offset);
    actor->model->position.x += ((rand() & 0xFFFF) * 0.000030517578f - 1.0f) * actor->def->offset_spread[0];
    actor->model->position.z += ((rand() & 0xFFFF) * 0.000030517578f - 1.0f) * actor->def->offset_spread[2];
    actor->model->rotation.x = ((rand() & 0xFFFF) * 0.000030517578f - 1.0f) * 3.1415927f;
    actor->model->rotation.y = ((rand() & 0xFFFF) * 0.000030517578f - 1.0f) * 3.1415927f;
    actor->model->rotation.z = 0.0f;
    motion->velocity.x = 0.0f;
    motion->velocity.y = actor->def->speed;
    motion->velocity.z = 0.0f;
    actor->model->position.y -= 1500.0f;
    offset.y = 3000.0f;
    offset.x = 0.0f;
    offset.z = 0.0f;
    func_001C1430(&actor->model->position, &offset, 1.0f);
    if (*(int *)0x70000010 != 0) {
        actor->model->position.y = *(f32 *)0x70000004 - actor->def->radius_half;
    } else {
        func_001A2A18(actor);
    }
}
