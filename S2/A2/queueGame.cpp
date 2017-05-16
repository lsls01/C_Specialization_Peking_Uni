#include <iostream>
#include <cstring>
using namespace std;

char m, f;

int queue(char q[], int n)
{
    if(q[n] == f)
        return n;
    if(q[n] == 0)
        return n;
    int r = n + 1;
    while(q[r] != 0 && q[r] != f)
        r = queue(q, r);

    if(q[r] == f)
    {
        cout << n << ' ' << r << endl;
        return r + 1;
    }
    else
        return r;
}

int main()
{
    char q[101];

    cin >> q;
    
    m = q[0];

    int n = strlen(q);
    for(int i = 0; i < n; i++)
        if(q[i] != m)
        {
            f = q[i];
            break;
        }

    queue(q, 0);

    return 0;
}

