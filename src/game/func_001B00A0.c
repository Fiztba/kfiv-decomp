typedef struct Obj {
    char *model;           /* 0x00 */
    char pad04[0x18];
    struct Obj *next;      /* 0x1C */
    char pad20[0x18];
    float radius;          /* 0x38 */
    float height;          /* 0x3C */
    char pad40[0x98];
    long flags;            /* 0xD8 */
} Obj;

extern Obj *D_004467E0;
float func_001B0178(void *, void *);
void func_00216778(float *, void *);

int func_001B00A0(float arg0, void *arg1) {
    float v[4] __attribute__((aligned(16)));
    Obj *obj;

    for (obj = D_004467E0; obj != 0; obj = obj->next) {
        if (((int)(obj->flags >> 1) & 1) == 0) continue;
        if (((int)(obj->flags >> 2) & 3) > 0) continue;
        func_00216778(v, obj->model + 0xC0);
        v[1] -= obj->height * 0.5f;
        if (func_001B0178(arg1, v) <= arg0 + obj->radius) return 1;
    }
    return 0;
}
