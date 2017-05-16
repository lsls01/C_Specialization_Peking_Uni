#include <iostream>
using namespace std;
int main() {
	float n, distance;
	float bike, walk;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
        cin >> distance;
        bike = 50 + distance / 3.0;
        walk = distance / 1.2;
        if(bike < walk) cout << "Bike" << endl;
        else
            if(bike > walk) cout << "Walk" << endl;
            else cout << "All" << endl;
    }
    return 0;
}