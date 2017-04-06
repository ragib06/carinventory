//
//  CarPtr.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "Car.h"

#ifndef CarPtr_hpp
#define CarPtr_hpp

class CarPtr {
private:
    Car* car;
    unsigned int _id;
    CarPtr(const CarPtr&);
    CarPtr& operator=(const CarPtr&);
protected:
    static unsigned int nextId;
    static const size_t CACHE_SIZE;
//    static Car Cache[2];
public:
    CarPtr();
    ~CarPtr();
    Car* operator->() const;
    Car& operator*() const;
    
    void setCost(double cost);
};

#endif /* CarPtr_hpp */
