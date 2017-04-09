//
//  CarPtr.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "Car.h"
#include "CarFile.h"
#include "CarCache.h"

#ifndef CarPtr_hpp
#define CarPtr_hpp

class CarPtr {
private:
    CarFile* _carfile;
    unsigned int _id;
    
    CarPtr(const CarPtr&);
    CarPtr& operator=(const CarPtr&);
    Car* getCarInstance() const;
    
protected:
    static unsigned int nextId;
    static const size_t CACHE_SIZE;
    static CarCache* cache;
    
public:
    CarPtr();
    CarPtr(int year, Date date, double cost, String *make, String *model, String *picture);
    ~CarPtr();
    
    Car* operator->() const;
    Car& operator*() const;
    
    void initCar(int year, Date date, double cost, String *make, String *model, String *picture);
    void save();
};

#endif /* CarPtr_hpp */
