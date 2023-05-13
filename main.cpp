#include <iostream>
#include "MyMap.h"
#include <deque>
#include "Inheritance.h"
#include <cmath>

using namespace std;

class ADD {
public:
    int a, b;

    void operator()() {
        cout << this->a + this->b;
    }
};

void text01(int y, int x = 9) {
    cout << y + x;
}

int add(int x, int y) {
    return x + y;
}

int jianf(int x, int y, int(*Fp)(int x, int y)) {
    return x - y - Fp(x, y);
}

bool panduan(int x, int y) {
    if (x > y) return true;
    else return false;
}

int num1[10] = {1, 9, 8, 7, 5, 4, 3, 0, 6, 2};

int paixu(int num[], bool(Fp)(int x, int y)) {
    int x, k;
    for (int i = 0; i < 10; i++)
        cout << num[i] << " ";
    for (int i = 0; i < 10; i++) {
        k = i;
        for (int j = i; j < 10; j++) {
            if (Fp(num[k], num[j])) k = j;
            else continue;
        }
        if (k != i) {
            x = num[i];
            num[i] = num[k];
            num[k] = x;
        }
    }
}

int N = 100, M = 20;

auto f = [](int x, int y) -> int {
    M = 10;
    return x + y;
};

/*int main() {
    paixu(num1, panduan);
    cout<<endl;
    for(int i=0;i<10;i++)
        cout<<num1[i]<<" ";
    cout<<endl;
    cout<<f(10,20)<<" "<<M;
}*/
int MyCalculate(int x) {
    return x * x;
}

double Q(long double x) {//目标函数
    //return 3 * pow(x, 4) - 4 * pow(x, 3) - 12 * pow(x, 2);
    //return pow(x, 2) - x - 1;
    return pow(x, 3) - 3 * x + 1;
}

double Q(double x[]) {
    return 0.5*pow(x[0],2)+pow(x[1],2);
}

double F(long double &b, long double &c) {//求出搜索区间
    double a, h, q, ak;
    a = 0;
    ak = 0;
    h = 0.17;
    while (1) {
        q = Q(ak);
        ak += h;
        if (Q(ak) < q) {
            h = 2 * h;
            a = ak;
            ak = ak + h;
        } else {
            b = min(a, ak);
            c = max(a, ak);
            break;
        }
    }
    cout << "搜索区间为：" << b << " " << c << endl;
}
int main() {
    double x[2] = {1,1};
    double d[2] = {1,-1};
    while (1) {
        d = x+d;
    }
}

/*long double s0, s1, s2, s, a, b, e = 0.05,h = 0.2;
    F(a, b);
    s0 = a;     s2 = b;     s1 = (a+b)/2;
    while (1) {
        if (Q(s0) < Q(s1) && Q(s1) < Q(s2)) {
            if (fabs(s2 - s0) < e) {
                cout << "end" << "  " <<s1;
                break;
            }
        } else {
            long double t, x;
            t = s0;     x = s2;     s0 = s1;    s2 = t;     s1 = x;
        }
        s = s0 +h * (4 * Q(s1) - 3 * Q(s0) - Q(s2)) / (2 * (2 * Q(s1) - Q(s0) - Q(s2)));
        if (Q(s1) <= Q(s)) {
            if (s1 < s) {
                s2 = s;     continue;
            } else {
                s0 = s;     continue;
            }
        } else {
            if (s1 > s) {
                s2 = s1;    s1 = s;     continue;
            } else {
                s0 = s1;    s1 = s;     continue;
            }
        }
    }
*/












/*long double a, b, p, q, t;
    int i;
    F(a, b);
    i = 0;
    t = 0.618;
    while (1) {
        p = a + (1 - t) * (b - a);
        q = a + t * (b - a);
        if (Q(p) <= Q(q)) {
            if (fabs(q - a) <= 0.005) {
                cout << "end " << "极小值点为：" << p << " " << "迭代次数：" << i;
                break;
            } else {
                a = a;    b = q;    q = p;    p = a + (1 - t) * (b - a);    i += 1;
            }
        } else {
            if (fabs(b - p) <= 0.005) {
                cout << "end " << "极小值点为：" << q << " " << "迭代次数：" << i;
                break;
            } else {
                a = p;    b = b;    p = q;   q = a + t * (b - a);    i += 1;
            }
        }
    }*/






/*int x, k;
    cin >> x;
    int Num[x], h;
    for (int i = 0; i < x; i++)
        cin >> Num[i];
    for (int i = 0; i < 10; i++) {

    }*/