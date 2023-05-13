//
// Created by Di Yang on 2022/4/30.
//

#ifndef _HUFFMANTREE_H
#define _HUFFMANTREE_H
#include<iostream>

using namespace std;

int s1,s2,flag=0;

typedef struct{
    int weight;
    int parent,lc,rc;
}HN,*HuffmanTree;

void CaculateHuffmanTree(HuffmanTree &HT,int n);
void DeleteHuffmanTree(HuffmanTree&HT);

void CreateHuffmanTree(HuffmanTree &HT,int n){
    if(n<=1) return;
    int m=2*n-1;
    HT=new HN[m+1];
    for(int i=1;i<=m;++i){
        HT[i].parent=0;
        HT[i].lc=0;
        HT[i].rc=0;
    }
    for(int i=1;i<=n;++i)
        cin >> HT[i].weight;
    for(int i=n+1;i<=m;i++){
        for(int h=1;h<=i;h++){
            if(HT[h].parent==0&&flag==0) { s1 = h; flag=1;}
            if(HT[h].parent==0&&h!=s1) { s2 = h; flag=2;}
            if(flag==2) { flag=0; break; }
        }//初始化s1,s2;
        for(int j=1;j<i;j++){
            if(HT[s1].weight>HT[j].weight&&HT[j].parent==0&&s1!=j&&s2!=j){
                if(HT[s1].weight<HT[s2].weight)s2=s1;
                s1=j;
            } else
                continue;
        }
        //cout<<s1<<" "<<s2<<" "<<HT[s1].weight<<" "<<HT[s2].weight;
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lc=s1;HT[i].rc=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
        //cout<<" "<<HT[i].weight<<endl;
    }
    CaculateHuffmanTree(HT,m);
    DeleteHuffmanTree(HT);
}

void CaculateHuffmanTree(HuffmanTree &HT,int n){
    int p=0,j=2;
    for(int i=n;i>n/2+1;i--){
        cout<<HT[i].weight<<endl;
    }
}

void DeleteHuffmanTree(HuffmanTree&HT){
    if(HT){
        cout<<'1';
        delete[] HT;
        cout<<'2';
    }
}
#endif //_HUFFMANTREE_H
