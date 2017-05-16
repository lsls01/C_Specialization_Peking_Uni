#include <iostream>
using namespace std;
int main() {
	int n;
	bool result;
	while(cin >> n)
	{
        result = false;
        
        if(n % 3 == 0)
        {
            cout << '3';
            result = true;
        }
        if(n % 5 == 0)
        {
            if(result == true) cout << ' ';
            cout << '5';
            result = true;
        }
        if(n % 7 == 0)
        {
            if(result == true) cout << ' ';
            cout << '7';
            result = true;
        }
        if(result == false) cout << 'n';
        cout << endl;
    }
    return 0;
}