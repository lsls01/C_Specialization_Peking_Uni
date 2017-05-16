#include <iostream>
using namespace std;

int main () {
    int n, m;
    int a[500];
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int k = 0; k < m; k++)
    {
        int tmp = a[n - 1];
        for(int i = n - 1; i > 0; i--)
            a[i] = a[i - 1];
        a[0] = tmp;
    }
    
    for(int i = 0; i < n - 1; i++)
        cout << a[i] <<" ";
    cout << a[n - 1] << endl;
    return 0;
}