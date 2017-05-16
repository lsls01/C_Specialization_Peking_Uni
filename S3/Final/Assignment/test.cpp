#include <iostream>
using namespace std;

class AA{};
class BB{
    AA v1, *v2;
    int v4;
    static void a(){};
    public:
        BB()
        {
            a();
        }
};

int main()
{
    return 0;
}
