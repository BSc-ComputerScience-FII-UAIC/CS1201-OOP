#ifndef Student_H
#define Student_H
#include <iostream>
using namespace std;

class Student {
    char nume[105];
    char *mat[105];
    int note[105], n;
    public:
        Student(const char* x);
        char* GetName();
        void PrintNote();
        int& operator[](const char* x);
        operator float();
};

#endif
