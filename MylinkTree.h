//
// Created by Di Yang on 2022/4/25.
//

#ifndef _LINKTREE_H
#define _LINKTREE_H
#include <iostream>
using namespace std;

typedef struct LT{
    char data;
    int LTag,RTag;
    struct LT *lc,*rc;
}LT,*LBT;

void InitLinkTree(LBT&tree){
    char ch;
    cin >> ch;
    if(ch == '#')tree = NULL;
    else{
     tree=new LT;
     tree->data = ch;
     InitLinkTree(tree->lc);
     InitLinkTree(tree->rc);
    }
}
LT* pre;
void InThreadLinkTree(LBT &tree){

    if(tree){
        InThreadLinkTree(tree->lc);
        if(!tree->lc){
            tree->LTag =1;
            tree->lc=pre;
        }else if(!tree->rc){
            pre->RTag=1;
            pre->rc=tree;
        }else pre->RTag=0;
        pre=tree;
        InThreadLinkTree(tree->rc);
    }
}

void InorderTraversal(LBT tree){
    LT *p;
    p=tree->lc;
    while(p!=tree){
        while(p->LTag==0)p=p->lc;
            cout<<p->data;
        while(p->RTag==1&&p->rc!=tree){
            p=p->rc;
            cout<<p->data;
        }
        p=p->rc;
    }
}

void DT(LBT &tree) {
    if (tree) {
        DT(tree->lc);
        DT(tree->rc);
        cout<<'1';
        delete tree;
        cout<<'2';
    }
}

#endif //_LINKTREE_H
