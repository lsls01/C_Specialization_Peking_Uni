#include<iostream>
using namespace std;

int main()
{
	char s[80];
	int a = 0, e = 0, i = 0, o = 0, u = 0;
	cin.getline(s, 80);
	for(int j = 0; j < 80; j++)
	{
		if(s[j] == 'a') a += 1;
		if(s[j] == 'e') e += 1;
		if(s[j] == 'i') i += 1;
		if(s[j] == 'o') o += 1;
		if(s[j] == 'u') u += 1;
	}
	cout << a << " " << e << " " << i << " " << o << " " << u << endl;
	return 0;
}

/*
 * if I include <string>, then I can use
 * string s;
 * getline(cin,s);
 * len = s.size();
 */