#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2{
    private:
        int *a;
        int i, j;
    public:
        Array2()
        {
            a = NULL;
        }
        Array2(int x, int y)
        {
            i = x;
            j = y;
            a = new int[i * j];
        }
        Array2(Array2 &t)
        {
            i = t.i;
            j = t.j;
            a = new int[i * j];
            memcpy(a, t.a, sizeof(int) * i * j);
        }
        Array2 &operator = (const Array2 &t)
        {
            if(a != NULL) delete []a;
            i = t.i;
            j = t.j;
            a = new int[i * j];
            memcpy(a, t.a, sizeof(int) * i * j);
            return *this;
        }
        int *operator[](int x)
        {
            return a + x * j;
        }
        int &operator()(int x, int y)
        {
            return a[x * j + y];
        }
        ~Array2()
        {
            if(a != NULL)
                delete []a;
        }
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
