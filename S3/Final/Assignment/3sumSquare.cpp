#include <iostream>
using namespace std;

int sqr(int n)
{
    return n * n;
}

int sum(int a[], int n, int (* sqr)(int))   // pointer to function
{
    int s = 0;
    for(int i = 0; i < n; i++)
        s += sqr(a[i]);
    return s;
}

int main()
{
    int t, n, a[0x100];
    cin >> t;
    for(int c = 0; c < t; ++c)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        cout << sum(a, n, sqr) << endl;
    }
    return 0;
}
