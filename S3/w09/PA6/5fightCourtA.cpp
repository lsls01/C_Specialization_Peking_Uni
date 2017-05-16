#include <iostream>
#include <cmath>
#include <map>
using namespace std;

typedef map<int, int> Member;
int main()
{
    int n;      // number of new members
    cin >> n;
    Member member;
    member.insert(pair<int, int>(1000000000, 1));
    while(n--)
    {
        int id, power;
        cin >> id >> power;
        member.insert(pair<int, int>(power, id));
        Member::iterator i = member.find(id);
    }
    return 0;
}