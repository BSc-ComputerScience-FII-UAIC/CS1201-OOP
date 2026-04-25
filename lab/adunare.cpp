#include "oper.h"


class Inmultire: public Oper {
    public:
        Inmultire();
        int comp(int a, int b);
        char* getName();
};
