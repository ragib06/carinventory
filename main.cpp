//
//  main.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include <iostream>
//#include <vector>
#include "Inventory.h"
#include "String.h"
//#include "Date.h"
//#include "Car.h"
//#include "CarFile.h"
using namespace std;


int main(int argc, const char * argv[]) {
    
    
    Inventory VCS;
    
    VCS.Prompt();
    
    return 0;
}





void test() {
    String s1;
    String s2("hi");
    String s3(s2);
    String s4("hello");
    String s5(" ");
    String s6 = "hey";
    String s7 = s4 + " " + "hey" + s2;
    String s8 = "my,name,is,khan";
    
    Date d(4, 6, 2017);
    
    //    cout << "s1: " << s1.string() << endl;
    //    cout << "s2: " << s2.string() << endl;
    //    cout << "s3: " << s3.string() << endl;
    //    cout << "s4: " << s4.string() << endl;
    //    s2 += s5 + s4;
    //    cout << "s2: " << s2.string() << endl;
    //    cout << "s6: " << s6.string() << endl;
    //    cout << "s7: " << s7.string() << endl;
    
    
    
    
    //    Car car(1972, d, 2000.0, String("Audi"), String("A6"), String("Car1.jpg"));
    //    CarFile cf(&car, String("car"));
    //    cf.StoreCarToFile();
    //
    //    cout << "Car: " << car.toString().string() << endl;
    //
    //    Car *newCar = cf.LoadCarFromFile();
    ////    Car *newCar = Car::fromString(car.toString());
    //    cout << "New Car: " << newCar->toString().string() << endl;
    
    
    
    //    vector<String> tokens = s8.tokenize(",");
    //
    //    for(int i=0; i<tokens.size(); i++) {
    //        cout << tokens[i].string() << endl;
    //    }
}
