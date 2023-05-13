//
// Created by Di Yang on 2022/4/21.
//

#ifndef _MY_H
#define _MY_H

#include <string>
#include <iostream>

using namespace std;


template<class T>
class MyLink {
public:
    MyLink(const int capacity) {
        this->p = new T[capacity];
        size = capacity;
    }

    ~MyLink() {
        if (this->p != NULL) delete[] this->p;
        this->p = NULL;
    }

private:
    T *p;
    int size, capacity;
    string str;
};


#endif //_MY_H
