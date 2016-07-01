

#include "calendar.h"
#include "strlib.h"
using namespace std;

Month & operator++(Month & month)
{
    switch(month)
    {
        case JAN:
            month = FEB;
            break;
        case FEB:
            month = MAR;
            break;
        case MAR:
            month = APR;
            break;
        case APR:
            month = MAY;
            break;
        case MAY:
            month = JUN;
            break;
        case JUN:
            month = JUL;
            break;
        case JUL:
            month = AUG;
            break;
        case AUG:
            month = SEP;
            break;
        case SEP:
            month = OCT;
            break;
        case OCT:
            month = NOV;
            break;
        case NOV:
            month = DEC;
            break;
        case DEC:
            month = JAN;
    }
    return month;
}

Month & operator--(Month & month)
{
    switch(month)
    {
        case JAN:
            month = DEC;
            break;
        case FEB:
            month = JAN;
            break;
        case MAR:
            month = FEB;
            break;
        case APR:
            month = MAR;
            break;
        case MAY:
            month = APR;
            break;
        case JUN:
            month = MAY;
            break;
        case JUL:
            month = JUN;
            break;
        case AUG:
            month = JUL;
            break;
        case SEP:
            month = AUG;
            break;
        case OCT:
            month = SEP;
            break;
        case NOV:
            month = OCT;
            break;
        case DEC:
            month = NOV;
    }
    return month;
}

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

bool Date::operator==(Date date)
{
    return d == date.d && m == date.m && y == date.y;
}

bool Date::operator!=(Date date)
{
    return !(*this == date);
}

bool Date::operator<(Date date)
{
    return (y < date.y) || ((y == date.y) && (m < date.m)) || ((y == date.y) && (m == date.m) && (d < date.y));
}

bool Date::operator<=(Date date)
{
    return (*this < date) || (*this == date);
}


bool Date::operator>(Date date)
{
    return (y > date.y) || ((y == date.y) && (m > date.m)) || ((y == date.y) && (m == date.m) && (d > date.y));
}

bool Date::operator>=(Date date)
{
    return (*this > date) || (*this == date);
}

Date Date::operator+(int n)
{
    Date copy(*this);
    copy.d += n;
    while (copy.d > 28)
    {
        switch (copy.m)
        {
            case DEC:
                if (copy.d > 31)
                {
                    copy.m = JAN;
                    copy.d -= 31;
                    ++copy.y;
                }
                break;
            case FEB:
                if (isLeapYear(copy.y) && copy.d > 29)
                {
                    ++copy.m;
                    copy.d -= 29;
                }
                break;
            case APR:
            case JUN:
            case SEP:
            case NOV:
                if (copy.d > 30)
                {
                    ++copy.m;
                    copy.d -= 30;
                }
                break;
            default:
                if (copy.d > 31)
                {
                    ++copy.m;
                    copy.d -= 31;
                }
        }
    }
    return copy;
}

Date Date::operator-(int n)
{
    Date copy(*this);
    copy.d -= n;
    while (copy.d < 0)
    {
        switch(copy.m)
        {
            case JAN:
                copy.m = DEC;
                copy.d += 31;
                --copy.y;
                break;
            case MAR:
                if (isLeapYear(copy.y)) copy.d += 29;
                else copy.d += 28;
                --copy.m;
                break;
            case MAY:
            case JUL:
            case OCT:
            case DEC:
                copy.d += 30;
                --copy.m;
                break;
            default:
                copy.d += 31;
                --copy.m;
                break;
        }
    }
    return copy;
}

int Date::operator-(Date date)
{
    int days1 = 0;
    int days2 = 0;
    days1 += d - 1;
    days1 += (y - 1900) * 365;
    switch (m)
    {
        case JAN:
            break;
        case FEB:
            days1 += 31;
            break;
        case MAR:
            days1 += 59;
            break;
        case APR:
            days1 += 90;
            break;
        case MAY:
            days1 += 120;
            break;
        case JUN:
            days1 += 151;
            break;
        case JUL:
            days1 += 181;
            break;
        case AUG:
            days1 += 212;
            break;
        case SEP:
            days1 += 243;
            break;
        case OCT:
            days1 += 273;
            break;
        case NOV:
            days1 += 304;
            break;
        case DEC:
            days1 += 334;
    }
    days2 += date.d - 1;
    days2 += (date.y - 1900) * 365;
    switch (date.m)
    {
        case JAN:
            break;
        case FEB:
            days2 += 31;
            break;
        case MAR:
            days2 += 59;
            break;
        case APR:
            days2 += 90;
            break;
        case MAY:
            days2 += 120;
            break;
        case JUN:
            days2 += 151;
            break;
        case JUL:
            days2 += 181;
            break;
        case AUG:
            days2 += 212;
            break;
        case SEP:
            days2 += 243;
            break;
        case OCT:
            days2 += 273;
            break;
        case NOV:
            days2 += 304;
            break;
        case DEC:
            days2 += 334;
    }
    return days1 - days2;
}

Date & Date::operator=(Date date)
{
    d = date.d;
    m = date.m;
    y = date.y;
    return *this;
}

Date & Date::operator+=(int n)
{
    *this = *this + n;
    return *this;
}

Date & Date::operator-=(int n)
{
    *this = *this - n;
    return *this;
}

Date & Date::operator++()
{
    *this += 1;
    return *this;
}

Date Date::operator++(int)
{
    Date copy(*this);
    *this += 1;
    return copy;
}

Date & Date::operator--()
{
    *this -= 1;
    return *this;
}

Date Date::operator--(int)
{
    Date copy(*this);
    *this -= 1;
    return copy;
}
