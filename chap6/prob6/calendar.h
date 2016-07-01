#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <string>
#include <ostream>

enum Month { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

Month & operator++(Month & month);

Month & operator--(Month & month);

bool isLeapYear(int year);

int daysInMonth(Month month, int year);

std::string monthToString(Month month);

class Date
{
public:
    Date(Month month = JAN, int day = 1, int year = 1900);
    Date(int day = 1, Month month = JAN, int year = 1900);

    int getDay() { return d; }
    Month getMonth() { return m; }
    int getYear() { return y; }

    std::string toString();

    bool operator==(Date date);
    bool operator!=(Date date);
    
    bool operator<(Date date);
    bool operator<=(Date date);
    bool operator>(Date date);
    bool operator>=(Date date);

    Date operator+(int n);
    Date operator-(int n);
    int operator-(Date date);

    Date & operator=(Date date);
    Date & operator+=(int n);
    Date & operator-=(int n);

    Date & operator++();
    Date operator++(int);
    Date & operator--();
    Date operator--(int);

private:
    Month m;
    int d;
    int y;
};

std::ostream & operator<<(std::ostream & os, Date date);

#endif
