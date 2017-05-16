#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[501];
    int f[26] = {0};
    int flag[26] = {0};
    cin >> s;

    int len = strlen(s);

    for(int i = 0; i < len; i++)
    {
        if(s[i] < 'a')
            s[i] += 32;
        if(s[i] >= 'a' && s[i] <= 'z')
            f[s[i] - 'a']++;
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

    cout << (char)(second + 65) << '+' << (char)(second + 97) << ':' << f[second] << endl;

    return 0;
}
