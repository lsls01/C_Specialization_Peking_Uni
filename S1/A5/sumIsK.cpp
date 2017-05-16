#include <iostream>
using namespace std;
int main() {
	int n, k;
	int num[1000];
	bool result = false;
	
	cin >> n >> k;
	for(int i = 0; i < n; i++)
        cin >> num[i];
    for(int i = 0; i< n; i++)
        for(int j = i + 1; j < n; j++)
            if(num[i] + num[j] == k)
            {
                result = true;
                break;
            }
    if(result == true) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}