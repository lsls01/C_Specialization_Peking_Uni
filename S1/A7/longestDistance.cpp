#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
	int n;
	double x[100], y[100];
	double dis = 0.0;
	
	cin >> n;
	for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(sqrt(pow((x[j] - x[i]), 2) + pow((y[j] - y[i]), 2)) > dis)
                dis = sqrt(pow((x[j] - x[i]), 2) + pow((y[j] - y[i]), 2));
    cout << fixed << setprecision(4) << dis << endl;
    return 0;
}