#include "common.h"

extern u8 D_00349682[];
extern int D_003EF658[];
double sqrt(double);
int rand(void);
void func_0019C598(float, float *, float *);
int func_0019C688(int);
int func_001CE690(int, int, int, char, int, char, s16, int);

/* Plays a sound heard from the given direction, louder the nearer it is within its range, with a random detune. */
void func_001A07D0(u8 sound, float range, float distance, float angle) {
    float origin[4];
    float offset[4];
    float level;
    int volume;
    int pan;
    int detune;

    if (!(range < distance) && sound != 0xFF) {
        func_0019C598(angle, origin, offset);
        level = range * range - (range - distance) * (range - distance);
        volume = (int)((1.0 - sqrt(level) / range) * 64.0) * 1.5f;
        pan = (offset[0] + 1.0f) * 63.0f;
        volume = (float) volume * (float) D_00349682[0] * 0.015625f;
        if (volume >= 0x80) {
            volume = 0x7F;
        }
        detune = ((u64) rand() << 11) / 0x7FFFFFFF - 0x400;
        func_001CE690(func_0019C688(2), D_003EF658[0], 0, sound, 0x3C, volume, detune, (char) pan);
    }
}
