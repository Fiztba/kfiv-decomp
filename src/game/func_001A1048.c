#include "common.h"
#include "kf_map.h"
#include "kf_sound.h"

extern SoundJob D_004FF528;
extern SoundJobSpec D_004FF510;

int func_001A1000(void *sequence, int kind);

/* Sets up the step 1 sound job from the map slot's sound bank and runs it; `pending` stays set until it is done. */
int func_001A1048(MapSlot *slot, int pending) {
    SoundSpecSource *source;

    if (pending == 0) {
        return 0;
    }
    D_004FF528.unk1C = 0x106810;
    D_004FF528.unk18 = 3;
    D_004FF528.spec = &D_004FF510;
    source = slot->unk34;
    D_004FF510.size_a = source->size_a;
    D_004FF510.buffer_a = source->buffer_a;
    D_004FF510.buffer_b = source->buffer_b;
    D_004FF510.size_b = source->size_b;
    if (func_001A1000(&D_004FF528, slot->tag) == 0) {
        pending = 0;
    }
    return pending;
}
