#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <list>
#include <set>
using namespace std;

int t, num, bit[10], idx;

void Break() {
    idx = -1;
    while (num) {
        bit[++idx] = num % 10;
        num /= 10;
    }
    for (int i = 0, j = idx; i < j; ++i, --j) {
        swap(bit[i], bit[j]);
    }
}

int get(int a, int b) {
    int ret = 0;
    for (int i = a; i < b; ++i) {
        ret *= 10, ret += bit[i];
    }
    return ret;
}

void Print(int state) {
    int last = 0;
    for (int i = 1; i <= idx+1; ++i) {
        if (state & (1 << i)) {
            printf(" %d", get(last, i));
            last = i;
        }
    }
}

bool judge(int state, int &ret) {
    int last = 0;
    ret = 0;
    for (int i = 1; i <= idx+1; ++i) {
        if (state & (1 << i)) {
            ret += get(last, i);
            last = i;
        }
    }
    return ret <= t;
} 

int main()
{
    int mask, Max, cnt, state;
    while (scanf("%d %d", &t, &num), t | num) {
        int i;
        if (t == num) {
            printf("%d %d\n", t, num);
            continue;
        }
        mask = cnt = 0;
        Max = 0;
        Break();
        for (i = 1; i <= idx; ++i) {
            mask |= (1 << i); // 对掩码进行赋值
        } 
        for (i = 0; i <= mask; i+=2) {
            int t = i;
            t |= (1 << (idx+1));
            int ret;
            if (judge(t, ret)) {
                if (Max < ret) {
                    Max = ret;
                    state = t;
                    cnt = 1;
                }
                else if (Max == ret) ++cnt;
            }
        }
        if (Max == 0) puts("error");
        else if (cnt != 1) puts("rejected");
        else {
            printf("%d", Max);
            Print(state);
            puts("");
        }
    }
    return 0;
}
