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
#include <fstream>

class Car {
private:
    int _id;
    int _year;
    Date _date;
    double _cost;
    
    String *_make;
    String *_model;
    String *_picture;
    
public:
    Car();
    Car(int cid, int year, Date date, double cost, String *make, String *model, String *picture);
    ~Car();
    
    Car& operator=(const Car& rhs);
    
    int cid() const;
    int year() const;
    Date date() const;
    double cost() const;
    void cost(double newCost);
    String make() const;
    String model() const;
    String picture() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Car& obj);
    friend std::istream& operator>>(std::istream& is, Car& obj);
};



#endif /* Car_h */
