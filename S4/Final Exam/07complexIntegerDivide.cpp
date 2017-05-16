#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int dpo[51][51][51];
int dps[51][51][51];
int sums[51];
int dpt[51][51][51];
int sumt[51];
void fun1() { 
    memset(dpo, 0, sizeof(dpo));
    for (int num=1; num<=50; num++) {
        for(int b=1; b<=num; b++) {
            dpo[num][1][b]=1;
        }
    }
    for(int num=2; num<=50; num++) {
        for (int k=num; k>1; k--){      //k=1已被初始化
            for (int b=num/k; b>=1; b--) {
                dpo[num][k][b]=dpo[num-b][k-1][b]+dpo[num][k][b+1];
            }
        }
    }
}

void fun2() {    
    memset(dps, 0, sizeof(dps));
    for (int num=1; num<=50; num++) {
        for(int b=1; b<=num; b++) {
            dps[num][1][b]=1;
        }
    }
    for(int num=2; num<=50; num++) {
        for (int k=num; k>1; k--){      //k=1已被初始化
            for (int b=num/k; b>=1; b--) {
                dps[num][k][b]=dps[num-b][k-1][b+1]+dps[num][k][b+1];
            }
        }
    }
    memset(sums, 0, sizeof(sums));
    for (int num=1; num<=50; num++)
    {
        for (int k=1; k<=num; k++) {
            sums[num] += dps[num][k][1];
        }
    }
}

void fun3() {
    memset(dpt, 0, sizeof(dpt));
    for (int num=1; num<=50; num += 2) {
        for(int b=1; b<=num; b++) {
            dpt[num][1][b]=1;
        }
    }   
    for(int num=2; num<=50; num++) {
        for (int k=num; k>1; k--){      //k=1已被初始化
            for (int b=num/k; b>=1; b--) {
                if (b&1) { //b为奇数
                    dpt[num][k][b]=dpt[num-b][k-1][b]+dpt[num][k][b+1];
                }
                else {
                    dpt[num][k][b]=dpt[num][k][b+1];
                }               
            }
        }
    }
    
    memset(sumt, 0, sizeof(sumt));
    for (int num=1; num<=50; num++)
    {
        for (int k=1; k<=num; k++) {
            sumt[num] += dpt[num][k][1];
        }
    }
}

int main() {
    int num, k;
    fun1();
    fun2();
    fun3();
    while(cin>>num>>k) {    
        cout << dpo[num][k][1] << endl;
        cout << sums[num] << endl;
        cout << sumt[num] << endl;
    }
    return 0;
}
