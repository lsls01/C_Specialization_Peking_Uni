#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int y, m, d;
    int monthCarry = 0;
    int yearCarry = 0;

    scanf("%d-%d-%d", &y, &m, &d);
    
    if(m == 1 || m == 3 || m == 5 || m == 7 ||
       m == 8 || m == 10 || m == 12)
        if(d == 31)
        {
            d = 1;
            monthCarry = 1;
        }
        else
            d += 1;
    else if(m == 2)
    {
        if(d == 28)
        {
            if((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
                d += 1;
            else
            {
                d = 1;
                monthCarry = 1;
            }
        }
        else if(d == 29)
        {
            d = 1;
            monthCarry = 1;
        }
        else
            d += 1;
    }
    else
    {
        if(d == 30)
        {
            d = 1;
            monthCarry = 1;
        }
        else
            d += 1;
    }

    m += monthCarry;
    if(m == 13)
    {
        m = 1;
        yearCarry = 1;
    }

    y += yearCarry;

    cout << y << '-';
    cout << setfill('0') << setw(2) << m;
    cout << '-';
    cout << setfill('0') << setw(2) << d << endl;
    return 0;
}
