#include <iostream>
#include <cmath>
#include <set>
using namespace std;

bool isPrime(int iVal)
{
    for(int i = 2; i < sqrt(iVal); i++)
        if(iVal % i == 0)
            return false;
    return true;
}

int getFactor(int iVal)
{
    int n = 0, sum = 0;
    for(int i = 2; i < sqrt(iVal); i++)
    {
        if(iVal % i == 0)
        {
            n = iVal / i;
            if(i != n && isPrime(n))
                sum += 1;
            if(isPrime(i))
                sum += 1;
        }
    }
    return sum;
}
class Priority
{
    public:
        bool operator()(const int & a, const int & b)
        {
            int sumA = 0, sumB = 0;
            sumA = getFactor(a);
            sumB = getFactor(b);
            if(sumA < sumB)
                return true;
            else if(sumA > sumB)
                return false;
            else
            {
                if(a < b)
                    return true;
                else return false;
            }
        }
};

int main()
{
    int n;      // number of new members
    cin >> n;
    set<int, Priority> pq;
    while(n--)
    {
        int num;
        for(int i = 0; i < 10; i++)
        {
            cin >> num;
            pq.insert(num);
        }
        int min = *(pq.begin());
        int max = *(pq.rbegin());
        pq.erase(max);
        pq.erase(min);
        cout << max << ' ' << min << endl;
    }
    return 0;
}