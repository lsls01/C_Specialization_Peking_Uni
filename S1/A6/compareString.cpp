#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) // size from string
        s1[i] = toupper(s1[i]); // toupper from cctype
    for(int i = 0; i < s2.size(); i++)
        s2[i] = toupper(s2[i]);
    if(s1 < s2) cout << "<" << endl;
    else if(s1 > s2) cout << ">" << endl;
    else cout << "=" << endl;
    return 0;
}