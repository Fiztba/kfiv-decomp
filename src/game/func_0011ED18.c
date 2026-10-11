extern char D_00474AC0[];
extern char D_00474B60[];

void func_0010A880(void *, void *);
void func_0010A008(void);
void func_00109E88(void);
void func_00109A50(void);
void func_00109A80(int, long);
void func_00109AD0(void);

void func_0011ED18(void) {
    struct { int w[10]; } *a;
    int *b;

    a = (void *)D_00474AC0;
    b = (int *)D_00474B60;
    func_0010A880(a++, b++);
    func_0010A880(a++, b++);
    func_0010A880(a++, b++);
    func_0010A880(a++, b++);
    func_00109E88();
    func_0010A008();
    func_00109A50();
    func_00109A80(0x42, 0x44);
    func_00109A80(0x47, 0x5000D);
    func_00109AD0();
}
