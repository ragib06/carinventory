//
//  CarCache.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "CarPtr.h"

#ifndef CarCache_hpp
#define CarCache_hpp

class CarCache {
private:
    int _count;
    const int _size;
    CarPtr* _cache;
public:
    CarCache();
    CarCache(int cacheSize);
    ~CarCache();
};

#endif /* CarCache_hpp */
