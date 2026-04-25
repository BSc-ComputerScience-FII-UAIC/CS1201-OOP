#include "oper.h"


class Impartire: public Oper {
    public:
        Impartire();
        int comp(int a, int b);
        char* getName();
};
