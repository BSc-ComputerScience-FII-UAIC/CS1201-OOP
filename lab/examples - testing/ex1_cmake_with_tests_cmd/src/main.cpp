#include <iostream>
#include "../includes/fnctns.h"
#include <climits>

int main () {
    std::cout << "The first CMake test" << std::endl;
    std::cout << sqr(inc2(3)) << std::endl;
    std::cout << inc2(INT_MAX) << std::endl;
    std::cout << sqr(INT_MAX/5) << std::endl;
    return 0;
}
