//
//  Date.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "String.h"
#include <fstream>

#ifndef Date_hpp
#define Date_hpp

class Date {
private:
    int _day;
    int _month;
    int _year;
    
public:
    Date();
    Date(int month, int day, int year);
    
    friend std::ostream& operator<<(std::ostream& os, const Date& obj);
    friend std::istream& operator>>(std::istream& is, Date& obj);
};



#endif /* Date_hpp */
