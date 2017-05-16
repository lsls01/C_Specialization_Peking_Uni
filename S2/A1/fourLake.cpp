#include <iostream>
using namespace std;

int main()
{
    int i = 0, j = 0, k = 0, l = 0;
    int a = 0, b = 0, c = 0, d = 0;
    bool flag = false;

    for(i = 1; (i <= 4) && (flag == false); i++)
        for(j = 1; (j <= 4) && (flag == false); j++)
            for(k = 1; (k <= 4) && (flag == false); k++)
                for(l = 1; (l <= 4) && (flag == false); l++)
                    if(i == j || j == k || k == l ||
                       i == k || i == l || j == l)
                        continue;
                    else
                    {
                        a = (j == 1) + (l == 4) + (i == 3) + (k == 2);
                        if(a != 1)
                            continue;
                        b = (l == 1) + (j == 4) + (i == 2) + (k == 3);
                        if(b != 1)
                            continue;
                        c = (l == 4) + (j == 3);
                        if(c != 1)
                            continue;
                        d = (i == 1) + (k == 4) + (l == 2) + (j == 3);
                        if(d != 1)
                            continue;

                        cout << i << endl;
                        cout << j << endl;
                        cout << k << endl;
                        cout << l << endl;
                        flag = true;
                        break;
                    }
    return 0;
}
