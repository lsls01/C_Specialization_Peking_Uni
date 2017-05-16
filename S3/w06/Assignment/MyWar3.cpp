#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

class City;
class Weapon;
class HeadQuarter;
class Warrior;

int life[5], attackOrig[5]; // order is dragon, ninja, iceman, lion, wolf
const string warriorName[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
const string teamName[2] = {"red", "blue"};
const int order[2][5] = {{2, 3, 4, 1, 0}, {3, 0, 1, 2, 4}}; //order[0] is red, order[1] is blue
int hours, minutes; // time
const string weaponName[3] = {"sword", "bomb", "arrow"};
int weaponCount = 0;
int winner = -1;

int M; // initial life amount
int N; // number of cities
int R; // attack of arrow 
int K; // loyalty decrease rate
int T; // time in minutes

void printTime()
{
    cout.width(3);
    cout.fill('0');
    cout << hours << ':';
    cout.width(2);
    cout << minutes << ' ';
}
void gameStart(int i);

class City
{
    private:
        int cityID;
        int lastWinner;                 // 0 for red, 1 for blue
        int flag;
        int life;
        Warrior *warriors[4];
        Weapon *weapon[3];
    public:
        City(int id): cityID(id), lastWinner(-1), flag(-1), life(0) {}
        friend class Warrior;
        friend class HeadQuarter;
        void lionEscape();
        void match(City &lCity, City &rCity);
        void matchOutput();
        void addLife();
        void getLife(HeadQuarter *red, HeadQuarter *blue);
        void shoot(City &lCity, City &rCity);
};

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
        double morale;
        int curLife;    // current life
        int loyalty;
        int id;
        int teamColor;      // team teamColor
        int kind;       // warrior category
        int attack;
        bool hasMoved;      // this turn has moved, after infomation being put out, set back to false
        City *cityBelongTo;
        HeadQuarter *belongTo;

        Weapon *weapons[2];

    public:
        friend class HeadQuarter;
        friend class City;
        Warrior(int kind_, int teamColor_, int curLife_, int id_, int m, City *city, HeadQuarter *headQuarter):
            kind(kind_), teamColor(teamColor_), curLife(curLife_), id(id_), morale(-1), loyalty(-1),
            cityBelongTo(city), belongTo(headQuarter), hasMoved(false), attack(attackOrig[kind])
    {
        int weaponKind;

        switch(kind)
        {
            case 0:     //dragon
                weaponKind = id % 3;
                weapons[0] = new Weapon(weaponKind, ++weaponCount);
                morale = (float)m / curLife;
                cout << "Its morale is "
                    << fixed << setprecision(2) << morale << endl;
                break;
            case 1:     // ninja
                weaponKind = id % 3;
                weapons[0] = new Weapon(weaponKind, ++weaponCount);
                weaponKind = (id + 1) % 3;
                weapons[1] = new Weapon(weaponKind, ++weaponCount);
                break;
            case 2:     // iceman
                weaponKind = id % 3;
                weapons[0] = new Weapon(weaponKind, ++weaponCount);
                break;
            case 3:     // lion
                loyalty = m;
                cout << "Its loyalty is " << loyalty << endl;
            case 4:     // wolf
                break;
        }
        city -> warriors[0] = this;
    }

        void hit(){}
        void fightBack(){}
        void match(City &city);
        void matchOutput(City &city, int cityID);
        void shoot(City &city);
};

class HeadQuarter
{
    private:
        int m; // life amount;
        int amount[5]; // amount of each kind of Warrior, the order is the same with string WarriorName
        int totalAmount;    // total amount of warrior.
        int teamColor;      // team teamColor
        int nextProduce;

    public:
        friend class City;
        HeadQuarter(){}
        HeadQuarter(int redOrBlue)
        {
            this->m = M;
            teamColor = redOrBlue;
            nextProduce = 0;
            totalAmount = 0;
            for(int i = 0; i < 5; i++)
                amount[i] = 0;
        }
        void produce(City *city)
        {
            int kind = order[teamColor][nextProduce]; // which kind of Warrior to be produce
            int lifeConsume = life[kind]; // the life will cost
            if(lifeConsume <= m)
            {
                amount[kind]++;
                m -= lifeConsume;
                totalAmount++;
                printTime();
                cout << teamName[teamColor] << " " << warriorName[kind] << " " << totalAmount << " born" << endl;
                Warrior *warrior = new Warrior(kind, teamColor, lifeConsume, totalAmount, m, city, this);
                if(!city -> warriors[0])
                    city -> warriors[0] = warrior;
                else
                    city -> warriors[1] = warrior;
                nextProduce = (nextProduce + 1) % 5;
            }
        }
        ~HeadQuarter()
        {
            delete this;
        }
};

void City:: lionEscape()
{
    for(int i = 0; i < 2; i++)
        if(warriors[i] -> kind == 3 && warriors[i] -> loyalty == 0)
        {
            if((warriors[i] -> teamColor == 0 && warriors[i] -> cityBelongTo -> cityID != N + 1) ||
                    (warriors[i] -> teamColor == 1 && warriors[i] -> cityBelongTo -> cityID != 0))
            {
                printTime();
                cout << teamName[warriors[i] -> teamColor] << "lion " << warriors[i] -> id << " ran away" << endl;
                delete warriors[i];
                warriors[i] = NULL;
            }
        }
}

void City:: match(City &lCity, City &rCity)
{
    for(int i = 0; i < 2; i++)
        if(warriors[i] && warriors[i] -> hasMoved == false)
        {
            if(warriors[i] -> teamColor == 0 && cityID != N + 1)
            {
                warriors[i] -> match(rCity);
                warriors[i] = NULL;
            }
            else if(warriors[i] -> teamColor == 1 && cityID != 0)
            {
                warriors[i] -> match(lCity);
                warriors[i] = NULL;
            }
        }
}

void City:: matchOutput()
{
    for(int i = 2; i < 4; i++)
        for(int j = 0; j < 2; j++)
            if(!warriors[j])
            {
                warriors[j] = warriors[i];
                warriors[i] = NULL;
                break;
            }

    if(warriors[0] && warriors[1] && warriors[0] -> hasMoved == true && warriors[1] -> hasMoved == true)
    {
        if(warriors[0] -> teamColor == 0)
        {
            warriors[0] -> matchOutput(*this, cityID);
            warriors[1] -> matchOutput(*this, cityID);
        }
        else
        {
            warriors[1] -> matchOutput(*this, cityID);
            warriors[0] -> matchOutput(*this, cityID);
        }
    }
    else
    {
        for(int i = 0; i < 2; i++)
        {
            if(warriors[i] && warriors[i] -> hasMoved)
                warriors[i] -> matchOutput(*this, cityID);
        }
    }
}

void City:: addLife()
{
    life += 10;
}

void City:: getLife(HeadQuarter *red, HeadQuarter *blue)
{
    for(int i = 0; i < 2; i++)
        if(warriors[i] && !warriors[(i + 1) % 2])
        {
            if(warriors[i] -> teamColor == 0)
                red -> m += this -> life;
            else
                blue -> m += this -> life;
            this -> life = 0;
        }
}

void City:: shoot(City &lCity, City &rCity)
{
    for(int i = 0; i < 2; i++)
        if(!( (cityID == 1 && warriors[i] -> teamColor == 1) ||
              (cityID == N && warriors[i] -> teamColor == 0) ))
        {
            if(warriors[i] -> teamColor == 0)
                warriors[i] -> shoot(rCity);
            else
                warriors[i] -> shoot(lCity);
        }
}

void Warrior:: match(City &city)
{
    for(int i = 2; i < 4; i++)
        if(!city.warriors[i])
        {
            city.warriors[i] = this;
            break;
        }
    cityBelongTo = &city;
    hasMoved = true;
}

void Warrior:: matchOutput(City &city, int cityID)
{
    printTime();
    if(!city.warriors[0])
        city.warriors[0] = this;
    else
        city.warriors[1] = this;
    if(cityID != 0 && cityID != N + 1)
        cout << teamName[teamColor] << ' ' << warriorName[kind] << ' ' << id << "marched to city " << cityID << "with " 
            << curLife << " and elements and force " << attack << endl;
    else if(cityID == 0)
        cout << "bule " << warriorName[kind] << ' ' << id << "reached red headquarter with " << curLife 
            << " and elements and force " << attack << endl;
    else if(cityID == N + 1)
        cout << "red " << warriorName[kind] << ' ' << id << "reached blue headquarter with " << curLife 
            << " and elements and force " << attack << endl;
}

void Warrior:: shoot(City &city)
{
}

int main()
{
    int t; // how many test data

    cin >> t;
    for(int i = 0; i < t; i++)
        gameStart(i);

    return 0;
}

void gameStart(int i)
{

    hours = 0;
    minutes = 0;
    winner = -1;
    weaponCount = 0;

    cin >> M >> N >> R >> K >> T;
    for(int j = 0; j < 5; j++)
        cin >> life[j];
    for(int j = 0; j < 5; j++)
        cin >> attackOrig[j];

    HeadQuarter *red = new HeadQuarter(0);
    HeadQuarter *blue = new HeadQuarter(1);

    vector<City> *citys = new vector<City>;
    for (int i = 0; i <= N + 1; ++i) {
        City temp(i);
        citys -> push_back(temp);
    }
    cout << "Case:" << i + 1 << endl;
    for(int winner = -1; hours * 60 <= T; hours++)
    {
        minutes = 0;
        red -> produce(&citys -> at(0));
        blue -> produce(&citys -> at(N + 1));

        // lion escape
        minutes = 5;
        if(hours * 60 + minutes <= T)
        {
            for(vector<City>:: iterator i = citys -> begin(); i != citys -> end(); ++i)
                (*i).lionEscape();         // match first, then output result, cause the destination is the where
        }

        // match
        minutes = 10;
        if(hours * 60 + minutes <= T)
        {
            for(vector<City>:: iterator i = citys -> begin(); i != citys -> end(); ++i)
                (*i).match(*(i - 1), *(i + 1));         // match first, then output result, cause the destination is the where
            for(vector<City>:: iterator i = citys -> begin() + 1; i != citys -> end() - 1; ++i)
                (*i).matchOutput();
        }
        else
            break;

        // Add life for each city except headquarter
        minutes = 20;
        if(hours * 60 + minutes <= T)
        {
            for(vector<City>:: iterator i = citys -> begin() + 1; i < citys -> end() - 1; i++)
                (*i).addLife();
        }

        // Get life from city if only one warrior in the city
        minutes = 30;
        if(hours * 60 + minutes <= T)
        {
            for(vector<City>:: iterator i = citys -> begin() + 1; i < citys -> end() - 1; i++)
                (*i).getLife(red, blue);
        }

        // arrow shoot
        minutes = 35;
        if(hours * 60 + minutes <= T)
        {
            for(vector<City>:: iterator i = citys -> begin(); i < citys -> end(); i++)
                (*i).shoot(*(i - 1), *(i + 1));
        }

        if(winner != -1)
            break;
    }
    delete red;
    delete blue;
    delete citys;
}
