//
//  Date.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include <iostream>
#include "Date.h"

Date::Date() {
    _day = 1;
    _month = 1;
    _year = 1970;
}

Date::Date(int month, int day, int year) : _month(month), _day(day), _year(year) {
    
}

String Date::date() {
    String _date;
    
    return _date;
}