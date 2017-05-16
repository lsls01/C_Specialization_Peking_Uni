#include <iostream>
#include <iomanip>
using namespace std;

struct patient
{
    int id;
    float degree;
};

int main()
{
    int m;
    float a;
    cin >> m >> a;

    struct patient p[51];
    for(int i = 0; i < m; i++)
        cin >> p[i].id >> p[i].degree;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(p[j].degree < p[i].degree)
            {
                struct patient tmp = p[j];
                p[j] = p[i];
                p[i] = tmp;
            }
        }
    }

    bool printed = false;

    for(int i = 0; i < m; i++)
    {
        if(p[i].degree > a)
        {
            printed = true;
            cout << setfill('0') << setw(3) << p[i].id;
            cout << ' ';
            cout << fixed << setprecision(1) << p[i].degree << endl;
        }
    }

    if(printed == false)
        cout << "None.";
    return 0;
}

