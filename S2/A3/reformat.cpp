#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char a[5000][41];

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int len;
    int j = 0;
    for(int i = 0; i < n;)
    {
        if(j + strlen(a[i]) < 81)
        {
            j += strlen(a[i]);
            cout << a[i];

            if(i == n - 1)
                cout << endl;
            else
            {
                if(j + 1 + strlen(a[i + 1]) > 80)
                {
                    j = 0;
                    cout << endl;
                }
                else
                {
                    j++;
                    cout << ' ';
                }
            }

            i++;
        }
        else
        {
            j = 0;
            cout << endl;
        }
    }
    return 0;
}
