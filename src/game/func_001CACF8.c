#include "kf_map.h"

void func_00216C48(void *, void *, void *);
extern MapActor D_005B6100[][16];

/* Moves every active actor of a map slot by the delta, and adds its y to the float at 0x14. */
void func_001CACF8(int slot, Vector4 *delta) {
    int i;
    MapActor *actor;

    actor = D_005B6100[slot];
    for (i = 15; i >= 0; i--) {
        if (actor->flags & 1) {
            func_00216C48(&actor->body->position, &actor->body->position, delta);
            actor->unk14 += delta->y;
        }
        actor++;
    }
}
