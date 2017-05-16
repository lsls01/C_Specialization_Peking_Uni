#include <iostream>
#include <cstring>
using namespace std;

void reverse(char s[], int i)
{
    if(s[i] != '\0' && s[i] != ' ')
    {
        reverse(s, i + 1);
        cout << s[i];
    }
}
int main()
{
    char s[501];
    cin.getline(s, 501);
    reverse(s, 0);
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == ' ')
        {
            cout << ' ';
            reverse(s, i + 1);
        }
    return 0;
}
