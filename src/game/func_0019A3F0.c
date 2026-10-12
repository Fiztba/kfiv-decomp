#include "kf_entity.h"

int func_0019A418(EntityModel *, u8);

int func_0019A3F0(Entity *entity, s32 index) {
    return func_0019A418(entity->model, entity->params->unk60[index]);
}
