#include <iostream>
using namespace std;

int main()
{
    int m, k;
    cin >> m >> k;

    if(m % 19 == 0)
    {
        while(m != 0)
        {
            if(m % 10 == 3)
                k--;
            m /= 10;
        }
        if(k == 0)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
    return 0;
}
