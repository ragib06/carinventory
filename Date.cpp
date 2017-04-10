//
//  Date.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "Date.h"
#include <iostream>
#include <cstdio>


Date::Date() {
    _day = 1;
    _month = 1;
    _year = 1970;
}

Date::Date(int month, int day, int year) : _month(month), _day(day), _year(year) {
    
}


std::ostream& operator<<(std::ostream& os, const Date& obj) {
    os << obj._month << "/" << obj._day << "/" << obj._year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& obj) {
    char c;
    is >> obj._month;
    is >> c;
    is >> obj._day;
    is >> c;
    is >> obj._year;
    
    return is;
}