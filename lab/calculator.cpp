#include "inmultire.h"
#include <cstring>

Inmultire::Inmultire() {
    strcpy(nume, "Inmultire");
}

int Inmultire::comp(int a, int b) {
    return a*b;
}

char* Inmultire::getName() {
    return nume;
}
