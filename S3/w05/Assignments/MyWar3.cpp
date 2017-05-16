#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int life[5]; // order is dragon, ninja, iceman, lion, wolf
string WarriorName[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
string teamName[2] = {"red", "blue"};
int order[2][5] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}}; //order[0] is red, order[1] is blue
int hours; // time
string weaponName[3] = {"sword", "bomb", "arrow"};
int weaponCount = 0;

void produce(int n, int m, const int life[]);

class Weapon
{
    private:
        int weaponID;
        int weaponKind;
        int weaponAttack;
    public:
        Weapon(int weaponKind_, int weaponID_)
        {
            weaponKind = weaponKind_;
            weaponID = weaponID_;
        };
        Weapon(const Weapon &a)
        {
            weaponKind = a.weaponKind;
            weaponID = a.weaponID;
        };
        Weapon()
        {
        };
};

class Warrior
{
    private:
        float morale;
        int curLife;    // current life
        int loyalty;
        int id;
        int teamColor;      // team teamColor
        int kind;       // warrior category

        Weapon weapon1, weapon2;

    public:
        Warrior()
        {
        };
        Warrior(int kind_, int teamColor_, int curLife_, int id_, int m)
        {
            kind = kind_;
            teamColor = teamColor_;
            curLife = curLife_;
            id = id_;
            morale = 0;
            loyalty = 0;


            int weaponKind;

            switch(kind)
            {
                case 0:     //dragon
                    weaponKind = id % 3;
                    weapon1 = Weapon(weaponKind, ++weaponCount);
                    morale = (float)m / curLife;
                    cout << "It has a " << weaponName[weaponKind] 
                         << ",and it's morale is ";
                    cout << fixed << setprecision(2) << morale << endl;
                    break;
                case 1:     // ninja
                    weaponKind = id % 3;
                    weapon1 = Weapon(weaponKind, ++weaponCount);
                    weaponKind = (id + 1) % 3;
                    weapon2 = Weapon(weaponKind, ++weaponCount);
                    cout << "It has a " << weaponName[id % 3]
                         << " and a " << weaponName[(id + 1) % 3] << endl;
                    break;
                case 2:     // iceman
                    weaponKind = id % 3;
                    weapon1 = Weapon(weaponKind, ++weaponCount);
                    cout << "It has a " << weaponName[weaponKind] << endl;
                    break;
                case 3:     // lion
                    loyalty = m;
                    cout << "It's loyalty is " << loyalty << endl;
                case 4:     // wolf
                    break;
            }
        };
};

class HeadQuarter
{
    private:
        int m; // life amount;
        int amount[5]; // amount of each kind of Warrior, the order is the same with string WarriorName
        int totalAmount;    // total amount of warrior.
        int teamColor;      // team teamColor
        int nextProduce;

        Warrior warrior[100];

    public:
        HeadQuarter(int m, int redOrBlue)
        {
            this->m = m;
            teamColor = redOrBlue;
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
                int kind = order[teamColor][nextProduce]; // which kind of Warrior to be produce
                int lifeConsume = life[kind]; // the life will cost
                if(lifeConsume <= m)
                {
                    amount[kind]++;
                    m -= lifeConsume;
                    totalAmount++;
                    cout << setfill('0') << setw(3) << hours << " "
                         << teamName[teamColor] << " " << WarriorName[kind]
                         << " " << totalAmount << " born with strength "
                         << lifeConsume << "," << amount[kind] << " "
                         << WarriorName[kind] << " " << "in "
                         << teamName[teamColor] << " headquarter" << endl;
                    nextProduce = (nextProduce + 1) % 5;
                    hasProduced = true;
                    warrior[totalAmount - 1] = Warrior(kind, teamColor, lifeConsume, totalAmount, m);
                    break;
                }
                nextProduce = (nextProduce + 1) % 5;
            }
            if(hasProduced == false)
                cout << setfill('0') << setw(3) << hours << " " 
                     << teamName[teamColor] << " headquarter stops making warriors" << endl;
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
    HeadQuarter red(m, 0);
    HeadQuarter blue(m, 1);
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
