#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[5001];
    int f[26] = {0};
    char chars[27];
    int flag[26] = {0};
    cin >> s;

    int len = strlen(s);

    for(int i = 0; i < 26; i++)
        chars[i] = '0';

    for(int i = 0; i < len; i++)
    {
        if(s[i] < 'a')
            s[i] += 32;
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            for(int j = 0; j < 26; j++)
            {
                if(chars[j] == s[i])
                {
                    f[j]++;
                    break;
                }
                if(chars[j] != '0')
                {
                    j++;
                }
                else
                {
                    chars[j] = s[i];
                    f[j]++;
                    break;
                }
            }
        }
    }

    int max = 0, second = 0;
    bool repeat = true;
    for(int i = 0; i < 26; i++)
    {
        if(f[max] < f[i])
            max = i;
    }
    flag[max] = 1;

    while(repeat == true)
    {
        second = 0;
        while(flag[second] == 1)
            second++;
        for(int i = 0; i < 26; i++)
            if(flag[i] !=1 && f[second] < f[i])
                second = i;
        flag[second] = 1;
        if(f[max] != f[second]) repeat = false;
    }

    cout << (char)(chars[second] - 32) << '+' << chars[second] << ':' << f[second] << endl;

    return 0;
}
