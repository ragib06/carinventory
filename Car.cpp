//
//  Car.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "Car.h"


Car::Car() : _year(1970), _cost(0.0) {
    
}

Car::Car(int year, Date date, double cost, String make, String model, String picture) :
_year(year), _date(date), _cost(cost), _make(make), _model(model), _picture(picture) {
    
    
}