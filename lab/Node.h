#include "calculator.h"
#include <iostream>
#include <cstring>
using namespace std;

Calculator::Calculator() {
    n = 0;
}

void Calculator::operator+=(Oper* x) {
    bool found = false;
    for(int i = 0; i < n && !found; i++)
        if(strcmp(x -> getName(), a[i] -> getName()) == 0)
            found = true;
    if(!found) {
        a[n] = x;
        n++;
    }
}

void Calculator::operator-=(const char* x) {
    bool found = false;
    int p = 0;
    for(int i = 0; i < n && !found; i++)
        if(strcmp(x, a[i] -> getName()) == 0) {
            p = i;
            found = true;
        }
    if(found) {
        delete a[p];
        for(int i = p; i < n-1; i++)
            a[i] = a[i+1];
        n--;
    }
}

bool Calculator::operator[](const char* x) {
    bool found = false;
    for(int i = 0; i < n && !found; i++)
        if(strcmp(x, a[i] -> getName()) == 0)
            found = true;
    return found;
}

void Calculator::Compute(int a, int b) {
    for(int i = 0; i < n; i++) {
        int x = this -> a[i] -> comp(a, b);
        cout << this -> a[i] -> getName() << "(" << a << ", " << b << ") = " << x << '\n';
    }
}

Calculator::operator int() {
    return n;
}
