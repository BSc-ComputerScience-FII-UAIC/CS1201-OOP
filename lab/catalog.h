#include "catalog.h"
#include "student.h"
#include <cstring>

Catalog::Catalog() {
    n = 0;
}

void Catalog::operator+=(initializer_list<const char*> v) {
    initializer_list<const char*>::iterator it;
    for(it = v.begin(); it != v.end(); it++)
        this->addStudent(*it);
}

Student& Catalog::operator[](int x) {
    return (*st[x]);
}

Student& Catalog::operator[](const char* x) {
    for(int i = 0 ; i < n; i++)
        if(strcmp(st[i] -> GetName(), x) == 0)
            return (*st[i]);
    return (*st[0]);
}

int Catalog::GetCount() {
    return n;
}

void Catalog::addStudent(const char* x) {
    bool found = false;
    for(int i = 0; i < n && !found; i++)
        if(strcmp(x, st[i] -> GetName()) == 0)
            found = true;
    if(!found)
        st[n++] = new Student(x);
}
