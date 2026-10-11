#include "common.h"

typedef struct {
    char pad00[0x5C];
    float limit;
} Controller;

typedef struct {
    char pad00[0xD4];
    float unkD4;
} Body;

typedef struct {
    Body *body;
    char pad04[8];
    Controller *ctrl;
    char pad10[0x4C];
    int *target;
} Actor;

float func_001954A8(float *, float *);
float func_001957B8(float, float);

/* Returns 0 with no target, 1 if the turn to it is within the limit, else 0x101/0x201 by turn direction. */
int func_00172BB8(Actor *arg0) {
    float angle;
    float limit;
    int result;

    if (arg0->target == NULL) {
        return 0;
    }
    result = 1;
    angle = func_001954A8((float *)((int)arg0->body + 0xC0), (float *)arg0->target);
    angle = func_001957B8(arg0->body->unkD4, angle);
    limit = arg0->ctrl->limit;
    if (0.0f <= angle ? limit < angle : limit < -angle) {
        result = 0x101;
        if (0.0f <= angle) {
            result = 0x201;
        }
    }
    return result;
}
