//
//  CarCache.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "CarCache.h"
#include <iostream>
using namespace std;

CarCache::CarCache() : _size(2), _count(0), _next(0), _cache(NULL) {
    
}

CarCache::CarCache(int cacheSize) : _size(cacheSize), _count(0), _next(0) {
    _cache = new Car[_size];
}

CarCache::~CarCache() {
    delete[] _cache;
}

//Return car instance for car id carID, if found in cache
//Return NULL otherwise
Car* CarCache::findByID(int carID) {
    for(int i = 0; i < _count; i++) {
        if(_cache[i].cid() == carID) {
            return &_cache[i];
        }
    }
    
    return NULL;
}

//Cache the provided car instance
void CarCache::cacheCar(Car& car) {
    
    if(_count == _size) {
        cout << "*** CACHE: remove car " << _cache[_next].cid() << " ***" << endl;
    }
    
    cout << "*** CACHE: add car " << car.cid() << " ***" << endl;
    
    _cache[_next] = car;
    
    _next = (_next + 1) % _size;
    _count = (_count == _size) ? _size : _count + 1;
}