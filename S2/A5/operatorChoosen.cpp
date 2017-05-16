#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a, b, c;
    scanf("%d,%d,%d", &a, &b, &c);
    if(a + b == c)
        cout << "+";
    else if(a - b == c)
        cout << "-";
    else if(a * b == c)
        cout << "*";
    else if(b != 0 && a / b == c)
        cout << "/";
    else if(b != 0 && a % b == c)
        cout << "%";
    else
        cout << "error";
    return 0;
}
