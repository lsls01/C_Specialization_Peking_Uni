#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char a[256];
    while(n--)
    {
        cin >> a;
        int len = strlen(a);
        for(int i = 0; i < len; i++)
        {
            switch(a[i])
            {
                case 'A':
                    cout << 'T';
                    break;
                case 'T':
                    cout << 'A';
                    break;
                case 'G':
                    cout << 'C';
                    break;
                case 'C':
                    cout << 'G';
                    break;
            }
        }
        cout << endl;
    }
    return 0;
}
