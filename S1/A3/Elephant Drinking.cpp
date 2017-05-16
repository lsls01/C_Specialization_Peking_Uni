#include <iostream>
using namespace std;
int main() {
	int h, r;
	int n;

	cin >> h >> r;
	n = (int)(20000 / h / 3.14 / r / r);
	if(20000.0 > (r * r * 3.14 * h * n)) n++;
	cout << n << endl;
    return 0;
}