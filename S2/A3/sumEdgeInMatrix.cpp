#include <iostream>
using namespace std;

int main()
{
    int k, m, n;

    cin >> k;

    while(k--)
    {
        int sum = 0;
        int tmp;
        cin >> m >> n;

        for(int i = 0; i < n; i++)
        {
            cin >> tmp;
            sum += tmp;
        }

        for(int i = 1; i < m - 1; i++)
        {
            cin >> tmp;
            sum += tmp;
            for(int j = 1; j < n - 1; j++)
                cin >> tmp;
            if(n > 1)
            {
                cin >> tmp;
                sum += tmp;
            }
        }

        for(int i = 0; i < n && m > 1; i++)
        {
            cin >> tmp;
            sum += tmp;
        }

        cout << sum << endl;
    }
    return 0;
}
