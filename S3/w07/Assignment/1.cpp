#include <iostream>
using namespace std;
// 在此处补充你的代码
template <class T>
class CArray3D
{
    class CArray2D
    {
        class CArray1D
        {
            T * ts;
            public:
            CArray1D(int k)
            {
                ts = new int[k];
            }
            T & operator[] (int k)
            {
                return ts[k];
            }
        };
        private:
        CArray1D ** ca1Ds;
        public:
        CArray2D(int j, int k)
        {
            ca1Ds = new CArray1D *[j];
            for(int i = 0; i < j; i++)
            {
                CArray1D *ca1D = new CArray1D(k);
                ca1Ds[i] = ca1D;
            }
        }
        CArray1D & operator [] (int j)
        {
            return *ca1Ds[j];
        }
    };
    private:
    CArray2D ** ca2Ds;
    public:
    CArray3D(int i, int j, int k)
    {
        ca2Ds = new CArray2D *[i];
        for(int l = 0; l < i; l++)
        {
            CArray2D * ca2D = new CArray2D(j, k);
            ca2Ds[l] = ca2D;
        }
    }
    CArray2D & operator [] (int i)
    {
        return *ca2Ds[i];
    }
};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
