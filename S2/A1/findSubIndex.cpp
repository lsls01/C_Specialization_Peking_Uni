#include <iostream>
using namespace std;

int main()
{
    int n;
    int x[101];
    bool flag = false;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        if(x[i] == i)
        {
            cout << i << endl;
            flag = true;
            break;
        }
    if(flag == false)
        cout << 'N' << endl;
    return 0;
}
