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

//Create car instance and immediately store into file
void CarPtr::initCar(int year, Date date, double cost, String *make, String *model, String *picture) {
    
    _id = CarPtr::nextId++;
    
    Car* _car = new Car(_id, year, date, cost, make, model, picture);
    
    String filename = "car";
    
    char buffer[10];
    sprintf(buffer, "%d", _id);
    
    filename = filename + buffer;
    
    _carfile = new CarFile(filename);
    
    _carfile->storeCarToFile(_car);
    
    delete _car;
}


//Get car instance from either cache or file
Car* CarPtr::getCarInstance() const{
    
    //find car instance in cache
    Car* _car = cache->findByID(_id);
    
    if(_car == NULL) {  //car instance not available in cache
        
        //load car isntance from file
        _car = _carfile->loadCarFromFile();
        
        //cache the car instance
        cache->cacheCar(*_car);
        
        //erase the temporary copy
        delete _car;
        
        //return cached copy
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
    
    //find car instance in cache
    Car* _car = cache->findByID(_id);
    
    if(_car != NULL) {  //car instance actually in memory/cache
        _carfile->storeCarToFile(_car);
    }
}


