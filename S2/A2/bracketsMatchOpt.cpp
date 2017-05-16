#include <iostream>
#include <cstring>
using namespace std;

char a[101];
char flag[101];
int len = 0;

int match(int n)
{
    if(a[n] == ')')
        return n;

    if(n == len)
        return -1;

    if(a[n] != '(' && a[n] != ')')
        return match(n + 1);

    int r = n + 1;
    while(a[r] != ')' || flag[r] == true)
    {
        r = match(r);
        if(r == -1) break;
    }
    if(a[r] == ')')
    {
        flag[n] = 1;
        flag[r] = 1;
        return r + 1;
    }
    else
        return -1;
}

int main()
{
    char result;
    while(cin.getline(a, 101))
    {
        len = strlen(a);
        for(int i = 0; i < len; i++)
            flag[i] = 0;
        
        int n = 0;
        int tmp = 0;
        while(n < len)
        {
            if(a[n] == '(' && flag[n] == false)
                match(n);
            tmp = n;
            for(int i = n; i < len; i++)
                if(flag[i] == true)
                    tmp = i;
            if(tmp > n) n = tmp;
            else n++;
        }

        cout << a << endl;

        for(int i = 0; i < len; i++)
        {
            if(flag[i] == 0)
            {
                switch(a[i])
                {
                    case '(':
                        result = '$';
                        break;
                    case ')':
                        result = '?';
                        break;
                    default:
                        result = ' ';
                        break;
                }
            }
            else
                result = ' ';
            cout << result;
        }
        cout << endl;
    }
    return 0;
}
