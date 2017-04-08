//
//  CarPtr.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "CarPtr.h"
#include <cstdlib>
#include <iostream>
using namespace std;

unsigned int CarPtr::nextId = 1;
const size_t CarPtr::CACHE_SIZE = 2;
CarCache* CarPtr::cache = new CarCache(CarPtr::CACHE_SIZE);

CarPtr::CarPtr() : _carfile(NULL){
    
}

CarPtr::CarPtr(int year, Date date, double cost, String *make, String *model, String *picture) {
    initCar(year, date, cost, make, model, picture);
}

CarPtr::~CarPtr() {
    
    if(_carfile != NULL) {
        delete _carfile;
    }
    
    if(cache != NULL) {
        delete cache;
        cache = NULL;
    }
}


void CarPtr::initCar(int year, Date date, double cost, String *make, String *model, String *picture) {
    
    _id = CarPtr::nextId++;
    
    Car* _car = new Car(_id, year, date, cost, make, model, picture);
    
    String filename = "car";
    
    char buffer[10];
    sprintf(buffer, "%d", _id);
    
    filename = filename + buffer;
    
    _carfile = new CarFile(filename);
    
    _carfile->StoreCarToFile(_car);
    
    delete _car;
}



Car* CarPtr::getCarInstance() const{
    Car* _car = cache->findByID(_id);
    
    if(_car == NULL) {
        _car = _carfile->LoadCarFromFile();
        cache->cacheCar(*_car);
        delete _car;
        
        return cache->findByID(_id);
    }
    
    return _car;
}

Car* CarPtr::operator->() const {
    Car* _car = getCarInstance();
    return _car;
}


Car& CarPtr::operator*() const {
    Car* _car = getCarInstance();
    return *_car;
}


void CarPtr::save() {
    Car* _car = cache->findByID(_id);
    
    if(_car != NULL) {
        _carfile->StoreCarToFile(_car);
    }
}


