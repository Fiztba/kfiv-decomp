#include "common.h"

typedef struct {
    char pad00[0x0C];
    char *unk0C;
    char pad10[0x8C];
    u16 timer;       /* 0x9C */
    char pad9E[0x02];
    u16 unkA0;       /* 0xA0 */
    char padA2[0x2A];
    u8 state;        /* 0xCC */
    char padCD;
    char prev_state;            /* 0xCE */
    char padCF[0x09];
    u64 flags;        /* 0xD8 */
} Actor;

/* Steps the actor's four-state timer machine. */
void func_0018E9C0(Actor *actor) {
    s64 next;

    next = actor->state;
    actor->prev_state = next;
    switch ((char)next) {
    case 0:
        if (((int)(actor->flags >> 33) & 1)) {
            next = 2;
            actor->state = 2;
        }
        break;
    case 1:
        if (((int)(actor->flags >> 33) & 1)) {
            next = 2;
            actor->state = 2;
        } else if (actor->timer == 0) {
            actor->state = 0;
            next = 0;
        }
        actor->timer--;
        break;
    case 2:
        if (!(((int)(actor->flags >> 33) & 1))) {
            actor->state = 1;
            next = 1;
            actor->timer = *(u16 *)(actor->unk0C + 0x12);
        }
        break;
    case 3:
        actor->state = 3;
        next = 3;
        break;
    default:
        actor->state = 0;
        next = 0;
        break;
    }
    if ((char)next != actor->prev_state) {
        actor->unkA0 = 0;
    }
}
