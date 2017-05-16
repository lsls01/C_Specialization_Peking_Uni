#include <iostream>
#include <map>
#include <cmath>
using namespace std;

typedef map<int, int> Member;
Member member;
int main()
{
    ios:: sync_with_stdio(false);
    int n;      // number of new members
    cin >> n;
    member.insert(pair<int, int>(1, 1000000000));
    for(int i = 0; i < n; i++)
    {
        int id, power;
        cin >> id >> power;
        member.insert(pair<int, int>(id, power));
    }
    for(int i = 2, j = 0; j < n; j++, i++)
    {
        int diff = member.find(1) -> second - member.find(i) -> second;
        int id = 1;
        for(int k = 1; k <= i - 1; k++)
        {
            if(abs(member.find(k) -> second - member.find(i) -> second) < abs(diff))
            {
                diff = member.find(k) -> second - member.find(i) -> second;
                id = k;
            }
            else if(abs(member.find(k) -> second - member.find(i) -> second) == abs(diff) && diff > 0 &&
                    member.find(k) -> second - member.find(i) -> second < 0)
            {
                diff = member.find(k) -> second - member.find(i) -> second;
                id = k;
            }
        }
        cout << i << ' ' << id << endl;
    }
    return 0;
}
