#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int life[5]; // order is dragon, ninja, iceman, lion, wolf
string solderName[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string teamName[2] = {"red", "blue"};
int order[2][5] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}}; //order[0] is red, order[1] is blue
int hours; // time

void produce(int n, int m, const int life[]);

class headQuarter
{
    private:
        int m; // life amount;
        int amount[5]; // amount of each kind of solder, the order is the same with string solderName
        int totalAmount;
        int color;
        int nextProduce;
    public:
        headQuarter(int m, int redOrBlue)
        {
            this->m = m;
            color = redOrBlue;
            nextProduce = 0;
            totalAmount = 0;
            for(int i = 0; i < 5; i++)
                amount[i] = 0;
        }
        bool produce()
        {
            bool hasProduced = false;
            for(int i = 0; i < 5; i++)
            {
                int kind = order[color][nextProduce]; // which kind of solder to be produce
                int lifeConsume = life[kind]; // the life will cost
                if(lifeConsume <= m)
                {
                    amount[kind]++;
                    m -= lifeConsume;
                    totalAmount++;
                    cout << setfill('0') << setw(3) << hours << " "
                         << teamName[color] << " " << solderName[kind] << " " 
                         << totalAmount << " born with strength "
                         << lifeConsume << "," << amount[kind] << " "
                         << solderName[kind] << " " << "in "
                         << teamName[color] << " headquarter" << endl;
                    nextProduce = (nextProduce + 1) % 5;
                    hasProduced = true;
                    break;
                }
                nextProduce = (nextProduce + 1) % 5;
            }
            if(hasProduced == false)
                cout << setfill('0') << setw(3) << hours << " " 
                     << teamName[color] << " headquarter stops making warriors" << endl;
            return hasProduced;
        }
};

int main()
{
    int m; // initial life amount
    int n; // how many test data
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = 0; j < 5; j++)
            cin >> life[j];
        produce(i, m, life);
    }

    return 0;
}

void produce(int n, int m, const int life[])
{
    hours = 0;
    cout << "Case:" << n + 1 << endl;
    headQuarter red(m, 0);
    headQuarter blue(m, 1);
    bool redStopped = false;
    bool blueStopped = false;
    for(hours = 0; true; hours++)
    {
        if(redStopped == false)
            redStopped = !red.produce();
        if(blueStopped == false)
            blueStopped = !blue.produce();
        if(redStopped && blueStopped)
            break;
    }
}
