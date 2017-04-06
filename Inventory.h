//
//  Inventory.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "CarPtr.h"

#ifndef Inventory_hpp
#define Inventory_hpp

class Inventory {
private:
    int _count;
    const int _size = 5;
    CarPtr _container[5];
    int _selection;
public:
    Inventory();
    void CreateCar();
    void ListCars();
    bool SelectCar(int index);
    bool ChangeCost(double newCost);
    void SaveAll();
};

#endif /* Inventory_hpp */
