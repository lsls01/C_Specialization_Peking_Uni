#include <iostream>
using namespace std;
int main() {
	int n, max;
	int score[100];

	cin >> n;
	for(int i = 0; i < n; i++)
        cin >> score[i];
    max = score[0];
	for(int i = 1; i < n ; i++)
        if(score[i] > max) max = score[i];
	cout << max << endl;
    return 0;
}