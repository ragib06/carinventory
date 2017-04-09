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


String Date::toString() {
    
    char buffer[10];
    sprintf(buffer, "%d/%d/%d", _month, _day, _year);
    
    return String(buffer);
}

Date Date::fromString(String dateString) {
    int m, d, y;
    sscanf(dateString.string(), "%d/%d/%d", &m, &d, &y);
    
    return Date(m, d, y);
}