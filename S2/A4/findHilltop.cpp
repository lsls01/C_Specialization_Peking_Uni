#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int a[21][21];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            bool isHilltop = true;
            
            if(isHilltop && i - 1 >= 0)
            {
                if(a[i][j] < a[i - 1][j])
                    isHilltop = false;
            }
            if(isHilltop && i + 1 < m)
            {
                if(a[i][j] < a[i + 1][j])
                    isHilltop = false;
            }
            if(isHilltop && j - 1 >= 0)
            {
                if(a[i][j] < a[i][j - 1])
                    isHilltop = false;
            }
            if(isHilltop && j + 1 < n)
            {
                if(a[i][j] < a[i][j + 1])
                    isHilltop = false;
            }

            if(isHilltop)
                cout << i << ' ' << j << endl;
        }
    }
    return 0;
}
