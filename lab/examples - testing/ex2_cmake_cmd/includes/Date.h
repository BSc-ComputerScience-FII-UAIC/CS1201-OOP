#include <climits>
#include <string>
//
// Created by Dorel Lucanu on 4/28/21.
//

#ifndef DATE_DATE_H
#define DATE_DATE_H

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    void setToday(int aYear, int aMonth, int aDay);
    string to_string();
    string today();
    string tomorrow();
private:
    static bool isLeapYear(int year);
    static int daysNo(Date& d);
};


#endif //DATE_DATE_H
