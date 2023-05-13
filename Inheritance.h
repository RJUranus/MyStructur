//
// Created by Di Yang on 2022/10/31.
//

#ifndef TANGCISHE_INHERITANCE_H
#define TANGCISHE_INHERITANCE_H

#include <iostream>

using namespace std;

class MyInheritance {
public:
    MyInheritance() {
        this->InheritFlag = 0;
        this->InheritTime = 1;
    }

    int MyCalculate(int x) {
        return x * x;
    }

    void MyInheritance_Init() {
        cout << "Please enter your inheritance" << endl;
        cin >> this->InheritNum >> this->InheritLength >> this->InheritScale;
        this->AccumulateAdaptNumProportion = new int[this->InheritNum + 1];
        this->AdaptNumProportion = new int[this->InheritNum];
        this->InheritNumSecond = new int[this->InheritNum];
        this->InheritTarget = new int[this->InheritLength];
        this->Inherit_x = new int[this->InheritNum];
        this->adaptNum = new int[this->InheritNum];
        this->MiddleNum = this->InheritScale;
        for (int i = 0; i < this->InheritLength; i++) {
            cin >> this->InheritTarget[i];
        }
        for (int i = 0; i < this->InheritNum; i++) {
            for (int j = 0; j < this->InheritLength; j++) {
                cin >> this->InheritData[i][j];
            }
        }
        this->AccumulateAdaptNumProportion[0] = 0;
        for (int i = 0; i < this->InheritNum; i++) {
            this->Inherit_x[i] = 0;
            this->adaptNum[i] = 0;
            this->InheritNumSecond[i] = 0;
            this->AccumulateAdaptNumProportion[i] = 0;
            this->AdaptNumProportion[i] = 0;
        }
        this->InheritData_Clear();
    }

    void GetAdaptNumProportion() {
        int Num = 0;
        for (int i = 0; i < this->InheritNum; i++) {
            Num += this->adaptNum[i];
        }
        for (int i = 0; i < this->InheritNum; i++) {
            this->AdaptNumProportion[i] = (this->adaptNum[i] * 100) / Num;
        }
        this->InheritData_Clear();
        this->GetAccumulateAdaptNumProportion();
    }

    void GetAccumulateAdaptNumProportion() {
        for (int i = 1; i <= this->InheritNum + 1; i++) {
            this->AccumulateAdaptNumProportion[i] =
                    this->AccumulateAdaptNumProportion[i - 1] + this->AdaptNumProportion[i - 1];
        }
        this->AccumulateAdaptNumProportion[this->InheritNum] = 100;
        this->InheritData_Clear();
        this->MyInherit_Inherit();
    }

    void My_Count(int(Fp)(int x)) {
        for (int i = 0; i < this->InheritNum; i++) {
            for (int j = 0; j < this->InheritLength; j++) {
                if (j == 0) {
                    this->Inherit_x[i] = this->Inherit_x[i] + this->InheritData[i][j];
                    continue;
                } else {
                    this->Inherit_x[i] = this->Inherit_x[i] + this->InheritData[i][j] * this->MiddleNum;
                    this->MiddleNum = this->MiddleNum * this->InheritScale;
                }
            }
            this->MiddleNum = this->InheritScale;
        }
        for (int i = 0; i < this->InheritNum; i++)
            this->adaptNum[i] = Fp(this->Inherit_x[i]);
        this->InheritData_Clear();
        this->GetAdaptNumProportion();
    }

    void My_Count() {
        for (int i = 0; i < this->InheritNum; i++) {
            for (int j = 0; j < this->InheritLength; j++) {
                if (j == 0) {
                    this->Inherit_x[i] = this->Inherit_x[i] + this->InheritData[i][j];
                    continue;
                } else {
                    this->Inherit_x[i] = this->Inherit_x[i] + this->InheritData[i][j] * this->MiddleNum;
                    this->MiddleNum = this->MiddleNum * this->InheritScale;
                }
            }
            this->MiddleNum = this->InheritScale;
        }
        for (int i = 0; i < this->InheritNum; i++)
            this->adaptNum[i] = this->Inherit_x[i] * this->Inherit_x[i];
        this->InheritData_Clear();
        this->GetAdaptNumProportion();
    }

    void MyInherit_Inherit() {
        for (int i = 0; i < this->InheritNum; i++) {
            this->InheritNumSecond[i] = rand() % 100;
        }
        for (int i = 0; i < this->InheritNum; i++) {
            for (int j = 0; j < this->InheritNum; j++) {
                if (this->InheritNumSecond[i] > this->AccumulateAdaptNumProportion[j] &&
                    this->InheritNumSecond[i] < this->AccumulateAdaptNumProportion[j + 1]) {
                    for (int a = 0; a < this->InheritLength; a++)
                        this->InheritData1[i][a] = this->InheritData[j][a];
                }
            }
        }
        this->InheritData_Clear();
        this->Inherit_Transfer();
        this->InheritData_Clear();
        //this->MyInherit_Intersect();
        this->MyInherit_Variation();
    }

    void MyInherit_Intersect() {
        int r_;
        for (int i = 0; i < this->InheritNum; i = i + 2) {
            int x = rand() % 2;
            if (x != 0) {
                int y = rand() % this->InheritLength;
                if (y == 0) {
                    this->InheritData[i][y] = r_;
                    this->InheritData[i][y] = this->InheritData[i + 1][y];
                    this->InheritData[i + 1][y] = r_;
                } else
                    for (int j = y + 1; j < this->InheritLength; j++) {
                        this->InheritData[i][j] = r_;
                        this->InheritData[i][j] = this->InheritData[i + 1][j];
                        this->InheritData[i + 1][j] = r_;
                    }
            } else continue;
        }
        this->InheritData_Clear();
        this->MyInherit_Variation();
    }

    void MyInherit_Variation() {
        for (int i = 0; i < this->InheritNum; i++) {
            int x = rand() % this->InheritLength;
            if (x != 0) {
                for (int j = 0; j < x; j++)
                    this->InheritData[i][rand() % this->InheritLength] = rand() % this->InheritScale;
            } else continue;
        }
        this->InheritData_Clear();
        this->MyPrint();
    }

    int MyInherit_Judge() {
        for (int i = 0; i < this->InheritNum; i++) {
            for (int j = 0; j < this->InheritLength; j++) {
                if (this->InheritData[i][j] == this->InheritTarget[j]) {
                    this->InheritFlag = 1;
                    if (j == this->InheritLength - 1 && this->InheritFlag == 1)
                        return this->InheritFlag;
                    else
                        continue;
                } else {
                    this->InheritFlag = 0;
                    break;
                }
            }
        }
        return this->InheritFlag;
    }

    void MyInherit_Run() {
        this->My_Count();
        this->MyInherit_Inherit();
    }

    void MyPrint() {
        cout << this->InheritTime << endl;
        this->InheritTime++;
        this->InheritData_Clear();
        for (int i = 0; i < this->InheritNum; i++) {
            for (int j = 0; j < this->InheritLength; j++) {
                cout << this->InheritData[i][j] << " ";
            }
            cout << endl;
        }
        this->InheritData_Clear();
    }

    void InheritData_Clear() {
        for (int i = 0; i < this->InheritNum; i++)
            for (int j = 0; j < this->InheritLength; j++) {
                this->InheritData[i][j] = this->InheritData[i][j] % this->InheritScale;
                this->InheritData1[i][j] = this->InheritData1[i][j] % this->InheritScale;
            }
    }

    void Inherit_Transfer() {
        for (int i = 0; i < this->InheritNum; i++)
            for (int j = 0; j < this->InheritLength; j++) {
                this->InheritData1[i][j] = this->InheritData1[i][j] % this->InheritScale;
                this->InheritData[i][j] = this->InheritData1[i][j] % this->InheritScale;
                this->InheritData[i][j] = this->InheritData[i][j] % this->InheritScale;
            }
    }

    ~MyInheritance() {
        if (this->adaptNum != nullptr) {
            delete[] this->adaptNum;
            this->adaptNum = nullptr;
        }
        if (this->AdaptNumProportion != nullptr) {
            delete[] this->AdaptNumProportion;
            this->AdaptNumProportion = nullptr;
        }
        if (this->AccumulateAdaptNumProportion != nullptr) {
            delete[] this->AccumulateAdaptNumProportion;
            this->AccumulateAdaptNumProportion = nullptr;
        }
        if (this->Inherit_x != nullptr) {
            delete[] this->Inherit_x;
            this->Inherit_x = nullptr;
        }
        if (this->InheritNumSecond != nullptr) {
            delete[] this->InheritNumSecond;
            this->InheritNumSecond = nullptr;
        }
        if (this->InheritTarget != nullptr) {
            delete[] this->InheritTarget;
            this->InheritTarget = nullptr;
        }
    }

private:
    int InheritTime;
    int InheritFlag;
    int MiddleNum;
    int InheritNum;
    int InheritLength;
    int InheritScale;
    int *InheritNumSecond;
    int *AdaptNumProportion;//[10]= {0,0,0,0,0,0,0,0,0,0};
    int *AccumulateAdaptNumProportion;//[10]= {0,0,0,0,0,0,0,0,0,0};;
    int InheritData[10][10] = {0};
    int InheritData1[10][10] = {0};
    int *adaptNum;//[10]= {0,0,0,0,0,0,0,0,0,0};
    int *Inherit_x;//[10]={0};
    int *InheritTarget;
};
/*4 5 2
1 0 1 1 0
1 0 0 1 1
0 0 0 1 0
0 1 0 0 1

1 2 3 4 5
0 4 3 3 5
0 1 3 5 5
0 4 3 2 2
*/
#endif //TANGCISHE_INHERITANCE_H
