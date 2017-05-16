#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, j;
        cin >> n >> i >> j;
        int k = 0;
        for(int l = 0; l < i; l++)
            n = n >> 1;
        k += n & 1;
        int o = 0;
        for(int m = i + 1; m < j; m++)
        {
            if(o == 0)
                o = 1;
            else
                o = (o << 1) + 1;
            n = n >> 1;
        }
        k += (o << 1);
        n = n >> 1;
        n = n ^ 1;
        for(int m = 1; m <= j - i; m++)
            n = n << 1;
        k += n;
        for(int l = 0; l < i; l++)
            k = k << 1;
        cout << hex << k << endl;
    }
    return 0;
}
