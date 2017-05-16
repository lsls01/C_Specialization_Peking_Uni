#include <iostream>
using namespace std;
int main() {
	int min, max, result;
	int num[6];

	for(int i = 0; i < 6; i++)
        cin >> num[i];
    max = 0;
    min = 100;
	for(int i = 0; i < 6 ; i++)
	{
        if((num[i] % 2 == 0) && num[i] < min) min = num[i];
        if((num[i] % 2 == 1) && num[i] > max) max = num[i];
    }
    result = max - min;
    if(result < 0) result = 0 - result;
	cout << result << endl;
    return 0;
}