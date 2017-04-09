//
//  CarFile.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/7/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "String.h"
#include "Car.h"
#include <cstdio>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef CarFile_hpp
#define CarFile_hpp

class CarFile {
private:
    ifstream _ifs;
    ofstream _ofs;
    String _filename;
public:
    CarFile();
    CarFile(String filename);
    
    Car* loadCarFromFile();
    void storeCarToFile(Car* car);
};

#endif /* CarFile_hpp */
