#include "oper.h"


class Adunare: public Oper {
    public:
        Adunare();
        int comp(int a, int b);
        char* getName();
};
