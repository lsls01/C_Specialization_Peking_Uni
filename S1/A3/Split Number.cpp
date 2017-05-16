#include <iostream>
using namespace std;
int main() {
	int num;
	cin >> num;
	
	cout << num / 100 << endl;
	
	num -= (num / 100) * 100;
	cout << num /10 << endl;
	
	num -= (num / 10) * 10;
	cout << num << endl;
    return 0;
}