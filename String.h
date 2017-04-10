//
//  String.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include <cstdlib>
#include <cstring>
#include <fstream>

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
    
    String& operator=(const String& rhs);
    String& operator=(const char* str);
    
    String operator+(const String& rhs);
    String operator+(const char* str);
    
    String& operator+=(const String& rhs);
    
    friend std::ostream& operator<<(std::ostream& os, const String& obj);
    friend std::istream& operator>>(std::istream& is, String& obj);
    friend std::ifstream& operator>>(std::ifstream& isf, String& obj);
};



#endif /* String_hpp */
