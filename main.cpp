//
//  main.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include <iostream>
#include "String.h"
#include "Date.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    String s1;
    String s2("hi");
    String s3(s2);
    String s4("hello");
    String s5(" ");
    
    Date d(4, 6, 2017);
    
    cout << "s1: " << s1.string() << endl;
    cout << "s2: " << s2.string() << endl;
    cout << "s3: " << s3.string() << endl;
    cout << "s4: " << s4.string() << endl;
    s2 += s5 + s4;
    cout << "s2: " << s2.string() << endl;
//    cout << "d: " << d.printDate() << endl;
    
    return 0;
}
