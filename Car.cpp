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
#include <vector>
using namespace std;

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


String Car::toString() {
    String str;
    str = "";
    
    char buffer[10];
    
    sprintf(buffer, "%d", _id);
    str = str + buffer + "\n";
    
    sprintf(buffer, "%d", _year);
    str = str + buffer + "\n";
    
    str = str + _date.toString() + "\n";
    
    sprintf(buffer, "%.2lf", _cost);
    str = str + buffer + "\n";
    
    str = str + *_make + "\n";
    
    str = str + *_model + "\n";
    
    str = str + *_picture;
    
    return str;
}

Car* Car::fromString(String carString) {
    int numTokens = carString.tokenCount("\n");
    String** tokens = new String*[numTokens];
    carString.tokenize("\n", tokens, numTokens);
    
    if(numTokens != 7) {
        return NULL;
    }
    
    int cid;
    int year;
    double cost;
    
    sscanf(tokens[0]->string(), "%d", &cid);
    sscanf(tokens[1]->string(), "%d", &year);
    Date date = Date::fromString(*tokens[2]);
    sscanf(tokens[3]->string(), "%lf", &cost);
    
    Car* car = new Car(cid, year, date, cost, tokens[4], tokens[5], tokens[6]);
    
    for(int i = 0; i < numTokens; i++) {
        delete tokens[i];
    }
    
    delete[] tokens;

    return car;
}