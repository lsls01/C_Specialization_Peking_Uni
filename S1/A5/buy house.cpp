#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, k, m;
	bool result = false;
	while(cin >> n >> k)
	{
        result = false;
        for(m = 1; m <= 20; m++)
            if(m * n > 200 * pow((100 + k) / 100.0, (m - 1)))
            {
                result = true;
                break;
            }
        if(result == true)
            cout << m << endl;
        else cout << "Impossible" << endl;
	}
    return 0;
}