#include "kf_effect.h"
#include "kf_entity.h"

extern EffectSlot D_003F1750[];
extern EffectActor D_003F3550[];
extern char D_00413F80[];
extern int D_004468CC;
extern int D_004468D0;
extern EffectDef D_0052F260[];

/* Releases the live object slots and effects owned by the player whose definition is one of three special ones. */
void func_001A35D0(void) {
    EffectSlot *slot = D_003F1750;
    EffectActor *actor = D_003F3550;
    int i;

    for (i = 0; i < 0x60 && D_004468CC > 0; i++, slot++) {
        if ((slot->flags & EFFECT_SLOT_LIVE)
            && (EFFECT_SLOT_FLAG_PARTS(slot)->def == D_0052F260 || EFFECT_SLOT_FLAG_PARTS(slot)->def == D_0052F260 + 2
                || EFFECT_SLOT_FLAG_PARTS(slot)->def == D_0052F260 + 4)
            && slot->owner_entity == (Entity *)D_00413F80) {
            func_001A2AF8(slot);
        }
    }
    for (i = 0; i < 0x180 && D_004468D0 > 0; i++, actor++) {
        if ((actor->flags & EFFECT_FLAG_LIVE)
            && (actor->def == D_0052F260 || actor->def == D_0052F260 + 2 || actor->def == D_0052F260 + 4)
            && actor->owner_entity == (Entity *)D_00413F80) {
            func_001A2A18(actor);
        }
    }
}
