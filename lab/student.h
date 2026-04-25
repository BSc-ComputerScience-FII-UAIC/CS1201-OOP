#include <initializer_list>
#include "student.h"


class Catalog {
    Student *st[1005];
    int n;
    public:
        Catalog();
        void operator+=(initializer_list<const char*> v);
        Student& operator[](int x);
        Student& operator[](const char* x);
        int GetCount();
        void addStudent(const char* x);
};
