#include "common.h"
#include "kf_effect.h"
#include "kf_entity.h"
#include "kf_game.h"

extern GameStatus D_0038CC50;
extern int D_004468CC;
extern EffectSlot D_003F1750[];
extern EffectActor D_003F3550[];
extern EffectDef D_0052F260[];
extern void (*D_00402554[][2])(EffectActor *);

void func_001A24D8(EffectSlot *);
void func_00216778(void *, void *);

/* Steps every live effect: the object slots are released, then each effect actor is advanced. */
void func_001A1E88(void) {
    Entity *only_owner = NULL;
    EffectSlot *slot;
    EffectActor *actor;
    EffectDef *table0 = D_0052F260;
    EffectDef *table1 = &D_0052F260[2];
    EffectDef *table2 = &D_0052F260[4];
    int i;
    int j;
    char unused[0x20]; /* unused, but retail reserves the 0x20 bytes */

    if (D_0038CC50.unk30 & 0x400) {
        only_owner = D_0038CC50.unk40;
    }
    if (D_004468CC > 0) {
        slot = D_003F1750;
        for (i = 0; i < 0x60; i++, slot++) {
            if (!(slot->flags & EFFECT_SLOT_LIVE)) {
                continue;
            }
            if (only_owner == NULL || only_owner == slot->owner_entity || EFFECT_SLOT_FLAG_PARTS(slot)->def == table0 ||
                EFFECT_SLOT_FLAG_PARTS(slot)->def == table1 || EFFECT_SLOT_FLAG_PARTS(slot)->def == table2) {
                func_001A24D8(slot);
                if (D_003F1750 != NULL) {
                    continue;
                }
                break;
            }
        }
    }
    actor = D_003F3550;
    for (i = 0; i < 0x180; i++, actor++) {
        if (!(actor->flags & EFFECT_FLAG_LIVE)) {
            if (actor->unk90 > 0) {
                actor->unk90--;
            }
        } else if (only_owner == NULL || only_owner == actor->owner_entity || actor->def == table0 ||
                   actor->def == table1 || actor->def == table2) {
            func_00216778(&actor->unk70, &actor->model->position);
        }
    }
    actor = D_003F3550;
    for (i = 0; i < 0x180; i++, actor++) {
        if (!(actor->flags & EFFECT_FLAG_LIVE)) {
            continue;
        }
        if (only_owner == NULL || only_owner == actor->owner_entity || actor->def == table0 ||
            actor->def == table1 || actor->def == table2) {
            if (EFFECT_FLAG_PARTS(actor)->unk40 > 0) {
                EFFECT_FLAG_PARTS(actor)->unk40--;
            }
            for (j = 0; j < 3; j++) {
                if (actor->def->unk112[j] == actor->frame) {
                    func_001A2838(actor->def->unk10C[j], actor);
                }
            }
            D_00402554[actor->def->unk100][0](actor);
        }
    }
}
