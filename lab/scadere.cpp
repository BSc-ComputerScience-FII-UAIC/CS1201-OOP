#include "adunare.h"
#include <cstring>

Adunare::Adunare() {
    strcpy(nume, "Adunare");
}

int Adunare::comp(int a, int b) {
    return a+b;
}

char* Adunare::getName() {
    return nume;
}
