#include <iostream>
#include <cstring>
using namespace std;
int main() {
	char str[11], substr[4];
	int strLen, loc = 0;
	
	cin >> str >> substr;
	strLen = strlen(str);
	
	cout << str[0];
	for(int i = 0; i < strLen - 1; i++)
        if(str[i + 1] - str[loc] > 0)
        {
            loc = i + 1;
            cout << str[i + 1];
        }
    
    for(int i = 0; i < 3; i++)
        cout << substr[i];
    
    for(int i = loc + 1; i < strLen; i++)
        cout << str[i];
    cout << endl;
    return 0;
}