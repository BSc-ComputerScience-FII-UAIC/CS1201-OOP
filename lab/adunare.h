#include "oper.h"


class Scadere: public Oper {
    public:
        Scadere();
        int comp(int a, int b);
        char* getName();
};
