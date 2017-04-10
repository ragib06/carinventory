//
//  CarFile.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/7/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "CarFile.h"

CarFile::CarFile() {
    //nothing to initialize
}


CarFile::CarFile(String filename) {
    _filename = filename;
}

//Load and return car instance from file
Car* CarFile::loadCarFromFile() {
    
    _ifs.open (_filename.string(), ifstream::in);
    
    Car * car = new Car;
    _ifs >> *car;
    _ifs.close();

    return car;
}

//store car instance into corresponding file
void CarFile::storeCarToFile(Car* car) {
    
    if(car == NULL) {
        return;
    }
    
    remove(_filename.string());
    
    _ofs.open (_filename.string(), ofstream::out);
    _ofs << *car;
    _ofs.close();
    
}