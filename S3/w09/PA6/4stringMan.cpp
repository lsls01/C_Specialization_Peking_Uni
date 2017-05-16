#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

string s[22];
string myCopy();
string myAdd();
int myFind();
int myFindR();
void myInsert();
void myReset();
string getS();            // get real string S1, S2
int getI();            // get real integer N, X, L
bool strToInt(int &m, string _s);

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> s[i + 1];
    
    string command;
    while(cin >> command && command != "over")
    {
        switch(command.at(1))
        {
            case 'n':
                myInsert();
                break;
            case 'e':
                myReset();
                break;
            case 'r':
                if(command == "print")
                {
                    int _n;
                    cin >> _n;
                    cout << s[_n] << endl;
                }
                else
                    for(int i = 1; i <= n; i++)     // i starts from 1 not 0
                        cout << s[i] << endl;
                break;
        }
    }
    return 0;
}

string getS()
{
    string _s;
    cin >> _s;
    if(_s == "copy")
        return myCopy();
    else if(_s == "add")
        return myAdd();
    else
        return _s;
}

int getI()
{
    string _s;
    cin >> _s;
    if(_s == "find")
        return myFind();
    else if(_s == "rfind")
        return myFindR();
    else
        return atoi(_s.c_str());
}

string myCopy()
{
    return s[getI()].substr(getI(), getI());
}

string myAdd()
{
    string s1, s2;
    s1 = getS();
    s2 = getS();
    int m, n;
    if(strToInt(m, s1) && strToInt(n, s2))
    {
        m += n;
        char result[8];
        sprintf(result, "%d", m);
        return string(result);
    }
    else
        return s1 + s2;
}

int myFind()
{
    string _s;
    _s = getS();
    int n;
    n = getI();
    int pos;
    pos = s[n].find(_s);
    if(pos == string:: npos)        // npos is used to indicate not found
        pos = s[n].length();
    return pos;
}

int myFindR()
{
    string _s;
    _s = getS();
    int n;
    n = getI();
    int pos;
    pos = s[n].rfind(_s);
    if(pos == string:: npos)
        pos = s[n].length();
    return pos;
}

bool strToInt(int &m, string _s)
{
    bool is = true;
    int i = 0;
    for(m = 0; i < _s.length(); i++)
        if(_s.at(i) >= '0' && _s.at(i) <= '9')
            m = m * 10 + _s.at(i) - '0';
        else
        {
            is = false;
            break;
        }
    if(m > 99999)
        is = false;
    return is;
}

void myInsert()
{
    string _s;
    _s = getS();
    int n, x;
    n = getI();
    x = getI();
    s[n].insert(x, _s);
}

void myReset()
{
    string _s;
    _s = getS();
    int n;
    n = getI();
    s[n].assign(_s);
}
