#include<iostream>
using namespace std;

int main()
{
    int n, num = 0, tmp;
    cin >> n;
    
    tmp = n / 100;
    cout << tmp << endl;
    n -= tmp * 100;
    num += tmp;
    
    tmp = n / 50;
    cout << tmp << endl;
    n -= tmp * 50;
    num += tmp;
    
    tmp = n / 20;
    cout << tmp << endl;
    n -= tmp * 20;
    num += tmp;
    
    tmp = n / 10;
    cout << tmp << endl;
    n -= tmp * 10;
    num += tmp;
    
    tmp = n / 5;
    cout << tmp << endl;
    n -= tmp * 5;
    num += tmp;
    
    tmp = n / 1;
    cout << tmp << endl;
    n -= tmp * 1;
    num += tmp;
    
    return 0;
}