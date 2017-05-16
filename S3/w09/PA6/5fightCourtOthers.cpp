#include <iostream>
#include <map>
#include <cmath>
using namespace std;

typedef map<int, int> MAP;

int main()
{
	MAP::key_type strength;
	MAP::mapped_type id;
	MAP member;
	pair<MAP::iterator, bool> pairs;
	member[1000000000] = 1;
	int id1 = 0, id2 = 0, s1 = 0, s2 = 0;
	id1 = 1;
	s1 = 1000000000;
	int n;
	cin >> n;
	while (n--)
	{
        cin >> id >> strength;
		member[strength] = id;
		pairs = member.insert(MAP::value_type(strength, id));
		MAP::iterator i = pairs.first;

		if (i == member.begin())
		{
			i++;
			cout << id << ' ' << i -> second << endl;
			continue;
		}
		else
		{
			i--;
			id1 = i->second;
			s1 = i->first;
		}

		i++, i++;
		if (i != member.end())
		{
			id2 = i->second;
			s2 = i->first;
		}

		if (abs(s2 - strength) == abs(s1 - strength))
		{
			if (s1 < s2)
                cout << id << ' ' << id1 << endl;
			else
                cout << id << ' ' << id2 << endl;
		}
		else if ((abs(s1 - strength) < abs(s2 - strength)) || i == member.end())
			cout << id << ' ' << id1 << endl;
		else
			cout << id << ' ' << id2 << endl;
	}
	return 0;
}