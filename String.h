//
//  String.hpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include <cstdlib>
#include <cstring>

#ifndef String_hpp
#define String_hpp

class String {
private:
    char* _string;
    size_t _size;
public:
    String();
    String(char* str);
    String(const String& str);
    ~String();
    
    char* string() const;
    size_t size() const;
    
    String& operator=(const String& rhs);
    String& operator+(const String& rhs);
    String& operator+=(const String& rhs);
};

#endif /* String_hpp */
