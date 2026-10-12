#include "common.h"
#include "kf_map.h"
#include "kf_sound.h"

extern SoundJob D_003EF648;
extern SoundJobSpec D_003EF5A0;

int func_001A1000(void *sequence, int kind);

/* Loads the map slot's sound bank (the SoundSpecSource at unk34), waiting until the job is done. */
int func_001A10D8(MapSlot *slot) {
    SoundSpecSource *source;

    D_003EF648.unk18 = 3;
    D_003EF648.unk1C = 0x106810;
    source = slot->unk34;
    D_003EF648.spec = &D_003EF5A0;
    D_003EF5A0.size_a = source->size_a;
    D_003EF5A0.buffer_a = source->buffer_a;
    D_003EF5A0.buffer_b = source->buffer_b;
    D_003EF5A0.size_b = source->size_b;
    while (func_001A1000(&D_003EF648, 1) > 0) {
    }
    return 0;
}
