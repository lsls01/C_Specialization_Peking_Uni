# include <iostream>
using namespace std;

int main () {
    int n, count = 0;
    int a[101][101];
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 1; i < n - 1; i++)
        for(int j = 1; j < n - 1; j++)
            if((a[i - 1][j] - a[i][j] >= 50)&&
               (a[i + 1][j] - a[i][j] >= 50)&&
               (a[i][j - 1] - a[i][j] >= 50)&&
               (a[i][j + 1] - a[i][j] >= 50))
                count++;
    cout << count << endl;
    return 0;
}