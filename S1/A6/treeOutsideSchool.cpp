#include <iostream>
using namespace std;

int main()
{
    int a[10002];
    int m, l, ans = 0;
    int x, y;
    for(int i = 0; i < 10002; i++)
        a[i] = 0;
    // memset(a, 0, sizeof(a));
    cin >> l >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        for(int j = x; j <= y; j++)
            a[j] = 1;
    }
    for(int i = 0; i <= l; i++)
        if(a[i] == 0)
            ans++;
    cout << ans << endl;
    return 0;
}