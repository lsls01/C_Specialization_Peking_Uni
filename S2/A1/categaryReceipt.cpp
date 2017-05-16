#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int staffID[3] = {0};
    float num[3] = {0.0, 0.0, 0.0};
    int n = 0;
    char category = '0';
    float amount;
    // sum by category
    float sum[3] = {0.0, 0.0, 0.0};

    for(int i = 0; i < 3; i++)
    {
        cin >> staffID[i];
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> category;
            cin >> amount;
            num[i] += amount;
            switch(category)
            {
                case 'A':
                    sum[0] += amount;
                    break;
                case 'B':
                    sum[1] += amount;
                    break;
                case 'C':
                    sum[2] += amount;
                    break;
            }
        }
    }

    for(int i = 1; i <= 3; i++)
        for(int j = 0; j < 3; j++)
            if(staffID[j] == i)
            {
                cout << fixed << setprecision(2) << i << ' ' << num[i -1] << endl;
            }

    cout << fixed << setprecision(2) << "A " << sum[0] << endl;
    cout << fixed << setprecision(2) << "B " << sum[1] << endl;
    cout << fixed << setprecision(2) << "C " << sum[2] << endl;

    return 0;
}
