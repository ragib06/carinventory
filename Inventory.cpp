//
//  Inventory.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() : _count(0) {
    
}

bool Inventory::CreateCar() {
    if(_count == _size) {
        return false;
    }
    
    int year;
    cout << "Enter year: ";
    cin >> year;
    
    Date date;
    cout << "Enter date(mm/dd/yy): ";
    cin >> date;
    
    double cost;
    cout << "Enter price: ";
    cin >> cost;
    
    String make;
    String model;
    String picture;
    
    cout << "Enter make: ";
    cin >> make;
    
    cout << "Enter model: ";
    cin >> model;
    
    cout << "Enter picture: ";
    cin >> picture;
    
    _container[_count++].initCar(year, date, cost, &make, &model, &picture);
    
    return true;
}

void Inventory::ListCars() {
    cout << "Total Cars: " << _count << endl;
    for(int i = 0; i < _count; i++) {
        
        int cid = _container[i]->cid();
        
        cout << "====================" << endl;
        cout << "Car ID         : " << cid << endl;
        cout << "Car Year       : " << _container[i]->year() << endl;
        cout << "Car Date       : " << _container[i]->date() << endl;
        cout << "Car Cost       : " << _container[i]->cost() << endl;
        cout << "Car Make       : " << _container[i]->make() << endl;
        cout << "Car Model      : " << _container[i]->model() << endl;
        cout << "Car Picture    : " << _container[i]->picture() << endl;
    }
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
    
    _container[_selection - 1]->cost(newCost);
    
    return true;
}

void Inventory::SaveAll() {
    for(int i = 0; i < _count; i++) {
        _container[i].save();
    }
    
    cout << "All in-memory car instances are saved to disk!" << endl;
}

void Inventory::Prompt() {
    char c;
    
    cout << ">> ";
    cin >> c;
    while(c != 'q') {
        
        if(c == 'c') {
            
            if(this->CreateCar() == false) {
                cout << "Error: Inventory Full!" << endl;
            } else {
                cout << "New car added to the inventory!" << endl;
            }
            
        } else if(c == 'l') {
            
            this->ListCars();
            
        } else if(c == 'p') {
            
            double p;
            cout << "Enter price: ";
            cin >> p;
            
            this->ChangeCost(p);
            
        } else if(c == 's') {
            
            this->SaveAll();
            
        } else if(c >= '1' && c <= '5') {
            
            if(this->SelectCar(c - '1' + 1) == false) {
                cout << "Error: Wrong Car Number!" << endl;
            } else {
                cout << "Car index seleced: " << c - '1' + 1 << endl;
            }
            
        } else {
            cout << "Error: Invalid Command!" << endl;
        }
        
        cout << ">> ";
        cin >> c;
    }
}