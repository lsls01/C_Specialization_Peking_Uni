#include <iostream>
using namespace std;
int main() {
	int n, result; // number of apples
	int x, y;

	cin >> n >> x >> y;
	result = n - (y / x) - ((y % x == 0)?0:1);
	if(result < 0) result = 0;
	cout << result << endl;
    return 0;
}