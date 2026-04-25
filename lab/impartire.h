#include "oper.h"
#include "adunare.h"
#include "scadere.h"
#include "inmultire.h"
#include "impartire.h"

class Calculator {
    Oper* a[10];
    int n;
    public:
        Calculator();
        void operator+=(Oper* x);
        void operator-=(const char* x);
        bool operator[](const char* x);
        void Compute(int a, int b);
        operator int();
};
