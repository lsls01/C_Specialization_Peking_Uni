#include <iostream>
using namespace std;

int main()
{
    int n, m, sum = 0;
    char a[101][101];

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    cin >> m;

    for(int d = 1; d <= m; d++)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] == 'y')
                    a[i][j] = '@';
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] == '@')
                {
                    if(i + 1 < n && a[i + 1][j] == '.')
                        a[i + 1][j] = 'y';
                    if(i - 1 >= 0 && a[i - 1][j] == '.')
                        a[i - 1][j] = 'y';
                    if(j + 1 < n && a[i][j + 1] == '.')
                        a[i][j + 1] = 'y';
                    if(j - 1 >= 0 && a[i][j - 1] == '.')
                        a[i][j - 1] = 'y';
                }
            }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == '@')
                sum++;
    cout << sum << endl;
    return 0;
}

