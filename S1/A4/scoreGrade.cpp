#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n <= 100 && n >= 95) cout << 1 << endl;
    if(n < 95 && n >= 90) cout << 2 << endl;
    if(n < 90 && n >= 85) cout << 3 << endl;
    if(n < 85 && n >= 80) cout << 4 << endl;
    if(n < 80 && n >= 70) cout << 5 << endl;
    if(n < 70 && n >= 60) cout << 6 << endl;
    if(n < 60) cout << 7 << endl;
    return 0;
}