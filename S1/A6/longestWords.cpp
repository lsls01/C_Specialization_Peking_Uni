#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string s, longest;
    char c[500];
    int len = 0;
    cin.getline(c, 500);
    s = c;
    s[s.size() - 1] = ' ';
    stringstream ss(s);
    while(ss >> s)
        if(s.size() > len)
        {
            len = s.size();
            longest = s;
        }
    cout << longest << endl;
    return 0;
}