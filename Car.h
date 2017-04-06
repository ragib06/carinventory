//
//  Car.h
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#ifndef Car_h
#define Car_h

#include "String.h"
#include "Date.h"

class Car {
private:
    int _year;
    Date _date;
    double _cost;
    
    String _make;
    String _model;
    String _picture;
    
public:
    Car();
    Car(int year, Date date, double cost, String make, String model, String picture);
};

#endif /* Car_h */
