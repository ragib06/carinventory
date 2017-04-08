//
//  CarFile.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/7/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "CarFile.h"

CarFile::CarFile() {
    
}


CarFile::CarFile(String filename) {
    _filename = filename;
}


CarFile::~CarFile() {

}

Car* CarFile::LoadCarFromFile() {
    char buffer[256] = "";
    char linebuf[40];
    
    _ifs.open (_filename.string(), ifstream::in);
    
    while(_ifs >> linebuf) {
        strcat(buffer, linebuf);
        strcat(buffer, "\n");
    }
    
    _ifs.close();
    
    return Car::fromString(buffer);
}

void CarFile::StoreCarToFile(Car* car) {
    
    if(car == NULL) {
        return;
    }
    
    remove(_filename.string());
    
    _ofs.open (_filename.string(), ofstream::out);
    _ofs << car->toString().string();
    _ofs.close();
    
}