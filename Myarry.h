//
// Created by Di Yang on 2022/4/13.
//

#ifndef _M_H
#define _M_H

#include <iostream>
#include "MyTree.h"
//下午写交换函数，和修改函数。
using namespace std;

template<class T>
class MyArray {
public:
    MyArray() {//默认构造，默认为10
        this->Capacity = 10;
        this->size == this->Capacity;
        this->PArray = new T[this->Capacity];
    }

    MyArray(const int capacity) {//有参构造
        cout << "1" << endl;
        this->Capacity = capacity;
        this->size = 0;
        this->PArray = new T[this->Capacity];
    }

    MyArray(const MyArray &arr) {//拷贝构造
        cout << "2" << endl;
        this->Capacity = arr.Capacity;
        this->size = arr.size;
        this->PArray = new T[this->Capacity];
        for (int i = 0; i < this->size; i++) {
            this->PArray[i] = arr.PArray[i];
        }
    }

    T &operator[](int i) {//重载【】，能通过下标来访问数据
        return this->PArray[i];
    }

    MyArray &operator=(const MyArray &arr) {
        cout << "4" << endl;
        if (this->PArray != NULL) {
            delete[] this->PArray;
            this->PArray = NULL;
            this->Capacity = 0;
            this->size = 0;
        }
        this->Capacity = arr.Capacity;
        this->size = arr.size;
        this->PArray = new T[this->Capacity];
        for (int i = 0; i < this->size; i++) {
            this->PArray[i] = arr.PArray[i];
        }
        return *this;
    }

    void MySort(MyArray &arr){

    }

    void Push_back(const T arr) {
        if (this->size == this->Capacity) {//数组的自动扩展
            Extend();
        }
        this->PArray[this->size] = arr;
        this->size++;
    }

    void Pop() {
        if (this->size == 0)
            return;
        this->size--;
    }

    int GetSize() {
        return this->size;
    }

    int GetCapacity() {
        return this->Capacity;
    }

    void Print() {
        for (int i = 0; i < this->size; i++) {
            cout << this->PArray[i] << " ";
        }
        cout << endl;
    }

    void Print(int i) {
        cout << this->PArray[i] << endl;
    }

    void Modification(int Fit) {
        cin >> this->PArray[Fit];
    }

    void Extend(int i) {
        this->Capacity += i;
        T *p;
        p = new T[this->size];
        for (int j = 0; j < this->size; j++) p[j] = this->PArray[j];
        delete[] this->PArray;
        this->PArray = new T[this->Capacity];
        for (int j = 0; j < this->size; j++) this->PArray[j] = p[j];
        delete[] p;
        p = NULL;
    }

    void swap(int i, int j) {
        T *p;
        p = new T;
        *p = this->PArray[i];
        this->PArray[i] = this->PArray[j];
        this->PArray[j] = *p;
        delete p;
    }

    ~MyArray() {
        if (this->PArray != NULL) {
            cout << "3" << endl;
            delete[] this->PArray;
            cout << "4" << endl;
        }
        this->PArray = NULL;
    }

private:
    T *PArray;
    int size;
    int Capacity;

    void Extend() {
        this->Capacity = this->Capacity * 2;
        T *p;
        p = new T[this->size];
        for (int i = 0; i < this->size; i++) {
            p[i] = this->PArray[i];
        }
        delete[] this->PArray;
        this->PArray = new T[this->Capacity];
        for (int i = 0; i < this->size; i++) {
            this->PArray[i] = p[i];
        }
        delete[] p;
        p = NULL;
    }
};

#endif //_M_H
