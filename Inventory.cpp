//
//  Inventory.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "Inventory.h"

Inventory::Inventory() : _count(0) {
    
}

void Inventory::CreateCar() {
    if(_count == _size) {
        return;
    }
    
    //TODO: proper intialisation
    
    _count++;
}

void Inventory::ListCars() {
    
}

bool Inventory::SelectCar(int index) {
    if(index <= 0 || index >= _size) {
        return false;
    }
    
    _selection = index;
    return true;
}

bool Inventory::ChangeCost(double newCost) {
    if(_selection == 0) {
        return false;
    }
    
//    _container[_selection - 1]->setCost(newCost);
    
    return true;
}

void Inventory::SaveAll() {
    
}