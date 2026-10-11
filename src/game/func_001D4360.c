extern char D_0043F730[];

typedef struct {
    void (*fn[3])(void *);
} Table;

typedef struct {
    char pad[0x1C];
    int index;
    int flag;
} Owner;

void func_001D4360(Owner *arg0) {
    Table t = *(Table *)D_0043F730;

    if (arg0->flag == 0) {
        t.fn[arg0->index](arg0);
    }
}
