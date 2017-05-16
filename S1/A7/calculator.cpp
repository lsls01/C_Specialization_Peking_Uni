#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	long long x, y;
	char o;
	
	cin >> x >> y >> o;
	
	if(o == '+') cout << x + y;
	if(o == '-') cout << x - y;
	if(o == '*') cout << x * y;
	if(o == '/')
        if(y == 0) cout << "Divided by zero!";
        else cout << x / y;
    if(o != '+' && o != '-' &&
       o != '*' && o != '/')
        cout << "Invalid operator!";
    return 0;
}