#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int n, num[100], a = 0, b = 0, c = 0, d = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
        if(num[i] < 19) a += 1;
        if(num[i] > 18 && num[i] < 36) b += 1;
        if(num[i] > 35 && num[i] < 61) c += 1;
        if(num[i] > 60) d += 1;
    }
    cout << "1-18: ";
    cout << fixed << setprecision(2) << (100.0 * a / n) << '%' << endl;
    cout << "19-35: ";
    cout << fixed << setprecision(2) << (100.0 * b / n) << '%' << endl;
    cout << "36-60: ";
    cout << fixed << setprecision(2) << (100.0 * c / n) << '%' << endl;
    cout << "60-: ";
    cout << fixed << setprecision(2) << (100.0 * d / n) << '%' << endl;
    return 0;
}