#include "common.h"

typedef struct Func0019B150Node {
    unsigned char pad00[0x20];
    int unk20;
    unsigned char pad24[0x18];
    struct Func0019B150Node *unk3C;
} Func0019B150Node;

void func_00216C48(void *, void *, void *);
extern void *D_004470C8[2];

void func_0019B150(void *arg0) {
    int i;
    Func0019B150Node *node;

    i = 0;
    do {
        node = (Func0019B150Node *)D_004470C8[i];
        if (node != NULL) {
            do {
                if (node->unk20 != 0) {
                    func_00216C48(node, node, arg0);
                }
                node = node->unk3C;
            } while (node != NULL);
        }
        i++;
    } while (i < 2);
}
