#ifndef Oper_H
#define Oper_H

class Oper {
    protected:
        char nume[1005];
    public:
        virtual char* getName()=0;
        virtual int comp(int a, int b)=0;
};

#endif
