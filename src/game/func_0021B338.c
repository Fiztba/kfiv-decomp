#include "common.h"

int sceMcInit();

typedef struct
{
  int pad0[32];
  int p80;
  int p84;
  int p88;
  int state;
  int pad1[2];
  int p98;
  int p9c;
} McState;
extern McState D_01E4F278;

/* Init the memory card library, then clear the card state block if it succeeded. */
int func_0021B338(void) {
    int result;
    int count;
    int *p;

    result = sceMcInit();
    if (result == 0) {
        count = 3;
        D_01E4F278.state = D_01E4F278.p88 = 0;
        p = &D_01E4F278.pad0[28];
        do {
            p[-4] = 0;
            count -= 1;
            p[0] = 0;
            p += 1;
        } while (count >= 0);
    }
    return result;
}
