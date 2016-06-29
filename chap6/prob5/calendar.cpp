

#include "calendar.h"
#include "strlib.h"
using namespace std;

bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0)   return true;
    return false;
}

int daysInMonth(Month month, int year)
{
    switch (month)
    {
        case FEB:
            return isLeapYear(year) ? 29 : 28;
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            return 31;
        default:
            return 30;
    }
}

string monthToString(Month month)
{
    const char* months[] = {nullptr, "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    return months[month];
}

Date::Date(Month month, int day, int year)
{
    m = month;
    d = day;
    y = year;
}

Date::Date(int day, Month month, int year)
{
    d = day;
    m = month;
    y = year;
}

string Date::toString()
{
    return integerToString(d) + "-" + monthToString(m) + "-" + integerToString(y);
}


