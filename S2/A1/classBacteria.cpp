#include <iostream>
using namespace std;

int main()
{
    int n; // number of bacteria
    int id[100];
    double rate[100];

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int orig, final;
        cin >> id[i] >> orig >> final;
        rate[i] = (double)final / orig;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - i - 1; j++)
        {
            if(rate[j + 1] > rate[j])
            {
                int tmpID = id[j];
                id[j] = id[j + 1];
                id[j + 1] = tmpID;
                double tmpRate = rate[j];
                rate[j] = rate[j + 1];
                rate[j + 1] = tmpRate;
            }
        }

    double maxDiff = 0;
    int indexMaxDiff = 0;
    for(int i = 0; i < n - 1; i++)
    {
        double diff = rate[i] - rate[i + 1];
        if(maxDiff < diff)
        {
            maxDiff = diff;
            indexMaxDiff = i;
        }
    }

    cout << indexMaxDiff + 1 << endl;
    for(int i = indexMaxDiff; i >= 0; i--)
        cout << id[i] << endl;

    cout << n - indexMaxDiff - 1 << endl;
    for(int i = n - 1; i >= indexMaxDiff + 1; i--)
        cout << id[i] << endl;

    return 0;
}
