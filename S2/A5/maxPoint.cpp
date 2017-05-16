#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int orig[101][2], sorted[101][2];
    int j = 0;

    for(int i = 0; i < n; i++)
        cin >> orig[i][0] >> orig[i][1];

    for(int i = 0; i < n; i++)
    {
        bool isMaxPoint = true;
        for(int k = 0; k < n; k++)
        {
            if(i != k && orig[i][0] <= orig[k][0] && orig[i][1] <= orig[k][1])
            {
                isMaxPoint = false;
                break;
            }
        }
        if(isMaxPoint)
        {
            sorted[j][0] = orig[i][0];
            sorted[j][1] = orig[i][1];
            j++;
        }
    }

    for(int i = 0; i < j - 1; i++)
    {
        for(int k = 0; k < j - i - 1; k++)
        {
            if(sorted[k][0] > sorted[k + 1][0])
            {
                int tmp[2];
                tmp[0] = sorted[k][0];
                tmp[1] = sorted[k][1];
                sorted[k][0] = sorted[k + 1][0];
                sorted[k][1] = sorted[k + 1][1];
                sorted[k + 1][0] = tmp[0];
                sorted[k + 1][1] = tmp[1];
            }
        }
    }

    for(int i = 0; i < j - 1; i++)
        cout << '(' << sorted[i][0] << ',' << sorted[i][1] << "),";
    cout << '(' << sorted[j - 1][0] << ',' << sorted[j - 1][1] << ')';
    return 0;
}
