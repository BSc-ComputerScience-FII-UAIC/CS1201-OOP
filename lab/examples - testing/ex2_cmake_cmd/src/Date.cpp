#include <climits>
//
// Created by Dorel Lucanu on 4/28/21.
//

#include "../includes/Date.h"

void Date::setToday(int aYear, int aMonth, int aDay) {
    year = aYear;
    month = aMonth;
    day = aDay;
}

string Date::today() {
    return to_string();
}

string Date::tomorrow() {
    Date t = *this;
    t.day++;
    if (t.day > daysNo(*this)) {
        t.day = 1;
        t.month++;
        if (t.month > 12) {
            t.month = 1;
            t.year++;
        }
    }
    return t.to_string();
}

int Date::daysNo(Date& d) {
    if (d.month == 2) {
        if (isLeapYear(d.year))
        return 29;
        else return 28;
    }
    if (d.month%2 == 1 and d.month < 8)
        return 31;
    return 30;
}

bool Date::isLeapYear(int year) {
    return (year%4 == 0 and year%100 !=0) || (year%400 == 0) ;
}

string Date::to_string() {
    return ::to_string(day) + "." +
           ::to_string(month)+ "." +
           ::to_string(year);
}

