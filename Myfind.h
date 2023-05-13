//
// Created by Di Yang on 2022/5/15.
//

#ifndef _MYFIND_H
#define _MYFIND_H

#include <iostream>
#include <set>

using namespace std;

template<class T>
class MyFinder {
public:
    MyFinder() {
        this->length = 12;
        this->R = new T[this->length];
        this->size = 1;
    }

    void push_back(T data) {
        if (this->size != this->length) {
            this->R[this->size] = data;
            this->size++;
        } else
            return;
    }

    int i;

    int FLocation(MyFinder &p, int key) {
        this->R[0] = key;
        for (i = this->length; this->R[i] != key; --i);
        return i;
    }

    ~MyFinder() {
        if (this->R != NULL) {
            delete[] this->R;
        }
    }

    T *R;
    int length;
    int size;
};

typedef struct {
    int key;
} EL;
typedef struct BST {
    EL data;
    struct BST *LC, *RC;
} BST, *BS;

BS S;
void InsertBST(BS&T,EL e){
    if(!T){
        S=new BST;
        S->data=e;
        S->LC=NULL;
        S->RC=NULL;
        T=S;
    }
    else if(e.key<T->data.key)
        InsertBST(T->LC,e);
    else if(e.key>T->data.key)
        InsertBST(T->RC,e);
}

//二叉排序树的创建
EL e;
void CreatedBST(BS &T) {
    T=NULL;
    cin>>e.key;
    while(e.key!=0){
        InsertBST(T,e);
        cin>>e.key;
    }
}

//查找
BS SearchBST(BS&T,const int key){
    if((!T)||T->data.key==key)return T;
    else if(T->data.key>key) return SearchBST(T->LC,key);
    else return SearchBST(T->RC,key);
}
//删除一个数
void DeleteBST(BS&T,const int key){
    BS P=T,f=NULL;
    while(P){
        if(P->data.key==key) break;
        f=P;
        if(P->data.key>key) P=P->LC;
        else P=P->RC;
    }
    if(!P) return;
    BS Q=P;
    if((P->LC)&&(P->RC)){
        BS S=P->LC;
        while(S->RC){
            Q=S;S=S->RC;
        }
        P->data=S->data;
        if(Q!=P) Q->RC=S->LC;
        else Q->LC=S->LC;
        delete S;
        return;
    }
    else if(!P->RC){
        P=P->LC;
    }
    else if(!P->LC){
        P=P->RC;
    }
    if(!f) T=P;
    else if(Q==f->LC) f->LC=P;
    else f->RC=P;
    delete P;
}

//删除整个二叉树
void DeleteBST(BS &T) {
    if (T->RC != NULL) DeleteBST(T->RC);
    if (T->LC != NULL) DeleteBST(T->LC);
    delete T;
}

#endif //_MYFIND_H
