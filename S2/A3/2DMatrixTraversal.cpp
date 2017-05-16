#include <iostream>
using namespace std;

int main()
{
    int row, col, num;
    int a[100][100];
    int k = 0, l = 0;

    cin >> row >> col;

    num = row * col;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> a[i][j];

    if(row > col)
    {
        for(int count = 0; count < num;)
        {
            cout << a[k][l] << endl;
            count++;
            if(l == 0 || k == row - 1)
            {
                if(k < col - 1)
                {
                    l = k + 1;
                    k = 0;
                }
                else
                {
                    if(k == row - 1)
                        k = k + l;
                    k = k + 2 - col;
                    l = col - 1;
                }
            }
            else
            {
                k++;
                l--;
            }
        }
    }
    if(row < col)
    {
        for(int count = 0; count < num;)
        {
            cout << a[k][l] << endl;
            count++;
            if(l == 0 || k == row - 1)
            {
                if(k < row - 1)
                {
                    l = k + 1;
                    k = 0;
                }
                else
                {
                    l = l + row;
                    k = 0;
                    if(l > col - 1)
                    {
                        k = l - col + 1;
                        l = col - 1;
                    }
                }
            }
            else
            {
                k++;
                l--;
            }
        }
    }
    if(row == col)
    {
        for(int count = 0; count < num;)
        {
            cout << a[k][l] << endl;
            count++;
            if(l == 0 || k == row - 1)
            {
                if(k < col - 1)
                {
                    l = k + 1;
                    k = 0;
                }
                else
                {
                    k = l + 1;
                    l = row - 1;
                }
            }
            else
            {
                k++;
                l--;
            }
        }
    }

    return 0;
}
