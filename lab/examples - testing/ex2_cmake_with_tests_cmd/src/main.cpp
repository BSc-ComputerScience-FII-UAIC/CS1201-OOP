#include <iostream>
#include "../includes/Date.h"

int main() {
    Date d;
    d.setToday(2011,1,1);
    std::cout << "Today: " + d.today() << std::endl;
    std::cout << "Tomorrow: " + d.tomorrow() << std::endl;
    return 0;
}
