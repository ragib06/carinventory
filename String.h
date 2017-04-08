//
//  String.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

#ifndef String_hpp
#define String_hpp

class String {
private:
    char* _string;
    size_t _size;
public:
    String();
    String(const char* str);
    String(const String& str);
    ~String();
    
    char* string() const;
    int toInt() const;
    double toDouble() const;
    size_t size() const;
    vector<String*> tokenize(const char* delimeter);
    
    String& operator=(const String& rhs);
    String& operator=(const char* str);
    
    String& operator+(const String& rhs);
    String& operator+(const char* str);
    
    String& operator+=(const String& rhs);
};

#endif /* String_hpp */
