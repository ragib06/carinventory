//
//  String.cpp
//  CarInventory
//
//  Created by Ragib Ahsan on 4/6/17.
//  Copyright © 2017 Ragib Ahsan. All rights reserved.
//

#include "String.h"


/* ----------------- Constructors ------------------*/
String::String() {
    _string = NULL;
    _size = 0;
}


String::String(const char* str) {
    if(str == NULL) {
        return;
    }
    
    _size = strlen(str);
    _string = new char[_size + 1];
    strcpy(_string, str);
}


String::String(const String& str) {
    
    if(str.size() == 0) {
        return;
    }
    
    _size = str.size();
    _string = new char[_size + 1];
    strcpy(_string, str.string());
}



/* ----------------- Destructor ------------------*/
String::~String() {
    if(_string != NULL) {
        delete _string;
    }
}



/* ----------------- Member functions ------------------*/
char* String::string() const{
    return _string;
}

int String::toInt() const {
    return atoi(_string);
}


double String::toDouble() const {
    return atof(_string);
}

size_t String::size() const {
    if(_string == NULL) {
        return 0;
    }
        
    return strlen(_string);
}




/* ----------------- Operator Overloading ------------------*/
String& String::operator=(const String& rhs) {
    
    if(this == &rhs) {
        return *this;
    }
    
    delete[] _string;
    
    _size = rhs.size();
    _string = new char[_size + 1];
    strcpy(_string, rhs.string());
    
    return *this;
}

String& String::operator=(const char* str) {
    
    if(_string != NULL) {
        delete[] _string;
    }
    
    _size = strlen(str);
    _string = new char[_size + 1];
    strcpy(_string, str);
    
    return *this;
}


String String::operator+(const String& rhs) {
    
    if(_size == 0) {
        return String(rhs);
    }
    
    char* temp = new char[_size + rhs.size() + 1];
    strcpy(temp, _string);
    strcat(temp, rhs.string());
    
    String res(temp);
    
    delete[] temp;
    
    return res;
}

String String::operator+(const char* str) {
    
    if(_size == 0) {
        return String(str);
    }
    
    char* temp = new char[_size + strlen(str) + 1];
    strcpy(temp, _string);
    strcat(temp, str);
    
    String res = String(temp);
    
    delete[] temp;
    
    return res;
}

String& String::operator+=(const String& rhs) {
    
    size_t temp_size = _size + rhs.size();
    
    if(temp_size == 0) {
        return *this;
    }
    
    char* temp = new char[temp_size + 1];
    
    if(_size != 0) {
        strcpy(temp, _string);
    } else {
        strcpy(temp, "");
    }
    
    if(rhs.size() != 0) {
        strcat(temp, rhs.string());
    }
    
    _size = temp_size;
    delete[] _string;
    _string = temp;
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& obj) {
    os << obj.string();
    return os;
}

std::ifstream& operator>>(std::ifstream& isf, String& obj) {
    
    long long off = isf.tellg();
    isf.seekg (0, isf.end);
    
    long long length = isf.tellg();
    isf.seekg (off, isf.beg);
    
    char *buffer = new char[length + 1];
    isf >> buffer;
    obj = buffer;
    delete[] buffer;
    
    return isf;
}

std::istream& operator>>(std::istream& is, String& obj) {
    
    char buffer[80];
    is >> buffer;
    obj = buffer;
    
    return is;
}