//
// Created by Di Yang on 2022/5/21.
//

#ifndef _MYSORT_H
#define _MYSORT_H

#include <iostream>

using namespace std;

class MySort {
public:
    //直接插入法
    void InsertSort(int Array[], const int t) {
        int j;
        for (int i = 2; i < t; i++) {
            if (Array[i] < Array[i - 1]) {
                Array[0] = Array[i];
                Array[i] = Array[i - 1];
                for (j = i - 2; Array[0] < Array[j]; j--)
                    Array[j + 1] = Array[j];
                Array[j + 1] = Array[0];
            }
            cout << i << ":  ";
            for (int p = 1; p <= i; p++) {
                cout << Array[p] << " ";
            }
            cout << endl;
        }
    }

    //折半插入排序
    void BtSort(int A[], const int t) {
        int low, high, m;
        for (int i = 2; i < t; i++) {
            A[0] = A[i];
            low = 1;
            high = i - 1;
            while (low <= high) {
                m = (low + high) / 2;
                if (A[0] < A[m]) high = m - 1;
                else low = m + 1;
            }
            for (int j = i - 1; j >= high + 1; j--) A[j + 1] = A[j];
            A[high + 1] = A[0];
            cout << i - 1 << ":  ";
            for (int j = 1; j < t; j++) {
                cout << A[j] << " ";
            }
            cout << endl;
        }
    }

    //冒泡排序
    void BubbleSort(int A[], const int t) {
        int m = t - 1, g;
        int flag = 1;
        while ((m > 0) && (flag == 1)) {
            flag = 0;
            for (int i = 1; i <= m; i++) {
                if (A[i] > A[i + 1]) {
                    g = A[i + 1];
                    A[i + 1] = A[i];
                    A[i] = g;
                    flag = 1;
                }
            }
            --m;
            cout << t - m - 1 << ":  ";
            for (int j = 1; j < t; j++)
                cout << A[j] << " ";
            cout << endl;
        }
    }

    //简单选择排序
    void SelectSort(int A[], const int t) {
        int k;
        for (int i = 1; i < t; i++) {
            k = i;
            for (int j = i + 1; j < t; j++) {
                if (A[k] > A[j])
                    k = j;
            }
            if (k != i) {
                int g = A[i];
                A[i] = A[k];
                A[k] = g;
            }
            cout << i << ":  ";
            for (int j = 1; j < t; j++)
                cout << A[j] << " ";
            cout << endl;
        }
    }
};

#endif //_MYSORT_H
