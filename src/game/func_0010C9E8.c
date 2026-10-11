#include "common.h"

void func_00216778(void *, void *);
void func_00216BC0(void *, void *, void *);

typedef struct {
    float v[3];
    u8 bone;
    char pad[3];
} BoneSource;

typedef struct {
    float m[4];
} BoneMatrixRow;

/* Builds 32 transformed bone vectors from the actor source table. */
void func_0010C9E8(char *actor) {
    float vec[4];
    int i;
    BoneSource *src;
    BoneMatrixRow *dst;

    src = *(BoneSource **)(actor + 0x120);
    dst = *(BoneMatrixRow **)(actor + 0x124);
    if (actor != NULL) {
        for (i = 0; i < 32; i++, src++, dst++) {
            if (src->bone != 0xFF) {
                func_00216778(vec, src);
                vec[3] = 1.0f;
                func_00216BC0(dst, *(char **)(actor + 0xF8) + (src->bone << 7), vec);
                func_00216BC0(dst, actor + 0x40, dst);
            } else {
                func_00216778(dst, actor + 0xC0);
            }
        }
    }
}
