//
//  Date.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#ifndef Date_hpp
#define Date_hpp

#include "String.h"

class Date {
private:
    int _day;
    int _month;
    int _year;
    
public:
    Date();
    Date(int month, int day, int year);
    String date();
};

#endif /* Date_hpp */
