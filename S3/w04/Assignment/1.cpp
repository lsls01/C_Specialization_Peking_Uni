#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
// 在此处补充你的代码
    Complex & operator = (string s)
    {
        int pos = s.find("+");
        string partOne = s.substr(0, pos);
        string partTwo = s.substr(pos + 1, s.length() - pos - 2);
        r = atof(partOne.c_str());
        i = atof(partTwo.c_str());
        return *this;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
