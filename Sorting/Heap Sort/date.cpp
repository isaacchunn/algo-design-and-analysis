//
//  date.cpp
//  HeapSort
//
//  Created by Isaac on 11/9/23.
//
#include "date.h"

Date::Date()
{
    
}

Date::Date(int day, int month)
: day(day),
  month(month)
{
    
}

Date::~Date()
{
    
}

bool Date::operator >(Date const& other)
{
    //Assume 30 days, so the total value is (months * 30) + days;
    int thisDate = ((month - 1) * 30) + day;
    int thatDate = ((other.month-1) * 30) + other.day;
    return thisDate < thatDate;
    
}

//The operators are inversed due to the question
bool Date::operator <(Date const& other)
{
    int thisDate = ((month - 1) * 30) + day;
    int thatDate = ((other.month-1) * 30) + other.day;
    return thisDate > thatDate;
}
bool Date::operator >(int other)
{
    int thisDate = ((month - 1) * 30) + day;
    return thisDate < other;
}

bool Date::operator>=(Date const& other)
{
    //Assume 30 days, so the total value is (months * 30) + days;
    int thisDate = ((month - 1) * 30) + day;
    int thatDate = ((other.month-1) * 30) + other.day;
    return thisDate <= thatDate;
}
bool Date::operator<=(Date const& other)
{
    int thisDate = ((month - 1) * 30) + day;
    int thatDate = ((other.month-1) * 30) + other.day;
    return thisDate >= thatDate;
}

std::ostream& operator<<(std::ostream&os, const Date& date)
{
    os << date.day << " ";
    if(date.month -1 < 12)
        os <<Date::months[date.month-1];
    return os;
}
