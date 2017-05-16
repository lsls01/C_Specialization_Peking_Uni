#include <iostream>
using namespace std;

class CType
{
    public:
        int value;
        CType(): value(0) {};
        void setvalue(int n)
        {
            value = n;
        }
        CType & operator ++ (int)
        {
            static CType tmp = CType();
            tmp.value = value;
            value *= value;
            return tmp;
        }
        friend ostream & operator << (ostream &o, CType &c)
        {
            o << c.value;
            return o;
        }
};

int main(int argc, char* argv[])
{
    CType obj;
    int n;
    cin >> n;
    while(n)
    {
        obj.setvalue(n);
        cout << obj++ << " " << obj << endl;
        cin >> n;
    }
    return 0;
}
