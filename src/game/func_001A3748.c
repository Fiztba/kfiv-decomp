#include "kf_effect.h"
#include "kf_entity.h"

extern EffectSlot D_003F1750[];
extern EffectActor D_003F3550[];
extern FxTableEntry D_00402DA8[];
extern char D_00413F80[];
extern int D_004468CC;
extern int D_004468D0;
extern EffectDef D_0052F260[];

/* Releases the live object slots and effects owned by the player, unless their definition is one of three special ones. */
void func_001A3748(void) {
    EffectSlot *slot = D_003F1750;
    EffectActor *actor = D_003F3550;
    int i;

    for (i = 0; i < 0x60 && D_004468CC > 0; i++, slot++) {
        if ((slot->flags & EFFECT_SLOT_LIVE) && slot->owner_entity == (Entity *)D_00413F80) {
            if (slot->effect_param != 0 && D_00402DA8[slot->effect_param].unk102 == 0) {
                EffectDef *def = EFFECT_SLOT_FLAG_PARTS(slot)->def;

                if (def != D_0052F260 && def != D_0052F260 + 2 && def != D_0052F260 + 4) {
                    func_001A2AF8(slot);
                }
            }
        }
    }
    for (i = 0; i < 0x180 && D_004468D0 > 0; i++, actor++) {
        if ((actor->flags & EFFECT_FLAG_LIVE) && actor->owner_entity == (Entity *)D_00413F80) {
            if (actor->effect_param != 0 && D_00402DA8[actor->effect_param].unk102 == 0) {
                EffectDef *def = actor->def;

                if (def != D_0052F260 && def != D_0052F260 + 2 && def != D_0052F260 + 4) {
                    func_001A2A18(actor);
                }
            }
        }
    }
}
