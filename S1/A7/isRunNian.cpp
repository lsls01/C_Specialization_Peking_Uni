#include <iostream>
using namespace std;
int main() {
	int year;
	bool result = false;
	cin >> year;
	
	if(year % 4 == 0) result = true;
	if(year % 100 == 0 && year % 400 != 0) result = false;
	if(year % 3200 == 0) result = false;
    if(result == false) cout << "N";
    else cout << "Y";
    return 0;
}