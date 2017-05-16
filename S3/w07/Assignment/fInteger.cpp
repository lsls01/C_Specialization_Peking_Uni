#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    cout << hex << n << endl;
    cout << setw(10) << setfill('0') << dec << n << endl;
    return 0;
}
