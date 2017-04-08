//
//  CarCache.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "Car.h"

#ifndef CarCache_hpp
#define CarCache_hpp

class CarCache {
private:
    int _count;
    int _next;
    int _size;
    Car* _cache;
public:
    CarCache();
    CarCache(int cacheSize);
    ~CarCache();
    
    Car* findByID(int carID);
    void cacheCar(Car& car);
};

#endif /* CarCache_hpp */
