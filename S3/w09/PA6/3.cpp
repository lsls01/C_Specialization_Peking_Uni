#include <iostream>
#include <set>
#include <string>
using namespace std;

void myAdd();
void myDel();
void myAsk();
multiset<int> i;
set<int> old;

int main() {
    int n;
    cin >> n;
    string command;
    for(int i = 0; i < n; i++)
    {
        cin >> command;
        switch(command.at(1))
        {
            case 'd':
                myAdd();
                break;
            case 'e':
                myDel();
                break;
            case 's':
                myAsk();
                break;
        }
    }
    return 0;
}

void myAdd()
{
    int a;
    cin >> a;
    i.insert(a);
    old.insert(a);
    cout << i.count(a) << endl;
}

void myDel()
{
    int a;
    cin >> a;
    cout << i.count(a) << endl;
    i.erase(a);
}

void myAsk()
{
    int a;
    cin >> a;
    int count = i.count(a);
    if(count == 0 && old.end() == old.find(a))
        cout << "0 0" << endl;
    else
        cout << "1 " << count << endl;
}