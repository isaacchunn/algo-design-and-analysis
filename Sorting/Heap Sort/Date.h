//
//  Date.h
//  HeapSort
//
//  Created by Isaac on 11/9/23.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date{
private:
    int day;
    int month;
    inline static std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
public:
    Date();
    Date(int day, int month);
    ~Date();
    
    bool operator>(Date const& other);
    bool operator<(Date const& other);
    bool operator>=(Date const& other);
    bool operator<=(Date const& other);
    bool operator>(int other);
    
    //Overloaded ostream
    friend std::ostream& operator<<(std::ostream&os, const Date& date);
};


#endif
