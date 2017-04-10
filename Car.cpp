//
//  Car.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "Car.h"
#include <cstdlib>
#include <cstdio>

Car::Car() : _year(1970), _cost(0.0), _make(NULL), _model(NULL), _picture(NULL){
    
}

Car::Car(int cid, int year, Date date, double cost, String *make, String *model, String *picture) :
_id(cid), _year(year), _date(date), _cost(cost) {
    
    _make = new String(*make);
    _model = new String(*model);
    _picture = new String(*picture);
    
}

Car::~Car() {
    
    if(_make != NULL)   delete _make;
    if(_model != NULL)   delete _model;
    if(_picture != NULL)   delete _picture;
}


Car& Car::operator=(const Car& rhs) {
    _id = rhs.cid();
    _year = rhs.year();
    _date = rhs.date();
    _cost = rhs.cost();
    
    if(_make != NULL)   delete _make;
    if(_model != NULL)   delete _model;
    if(_picture != NULL)   delete _picture;
    
    _make = new String(rhs.make());
    _model = new String(rhs.model());
    _picture = new String(rhs.picture());
    
    return *this;
}


int Car::cid() const{
    return _id;
}

int Car::year() const{
    return _year;
}

Date Car::date() const{
    return _date;
}

double Car::cost() const{
    return _cost;
}

void Car::cost(double newCost) {
    _cost = newCost;
}

String Car::make() const{
    return *_make;
}

String Car::model() const{
    return  *_model;
}

String Car::picture() const{
    return *_picture;
}



std::ostream& operator<<(std::ostream& os, const Car& obj) {
    os << obj.cid() << std::endl;
    os << obj.year() << std::endl;
    os << obj.date() << std::endl;
    os << obj.cost() << std::endl;
    os << obj.make() << std::endl;
    os << obj.model() << std::endl;
    os << obj.picture() << std::endl;
    
    return os;
}

std::istream& operator>>(std::istream& is, Car& obj) {
    String buffer;
    
    is >> buffer;
    obj._id = buffer.toInt();
    
    is >> buffer;
    obj._year = buffer.toInt();
    
//    is >> buffer;
//    obj._date = Date::fromString(buffer);
    obj._date = Date();
    is >> obj._date;
    
    is >> buffer;
    obj._cost = buffer.toDouble();
    
    obj._make = new String();
    is >> *obj._make;
    
    obj._model = new String();
    is >> *obj._model;
    
    obj._picture = new String();
    is >> *obj._picture;
    
    return is;
}