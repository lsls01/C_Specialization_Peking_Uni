#include <iostream>
using namespace std;

char maze[500][500];
int n, m;
char visited[500][500];
int x[2], y[2];

int traversal(int k, int l);

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> maze[i];

    for(int i = 0; i < 500; i++)
        for(int j = 0; j < 500; j++)
        {
            visited[i][j] = '0';
            if(maze[i][j] == 'S')
            {
                visited[i][j] = '1';
                x[0] = i;
                y[0] = j;
            }
            if(maze[i][j] == 'T')
            {
                x[1] = i;
                y[1] = j;
            }
        }

    cout << traversal(x[0], y[0]);

    return 0;
}

int traversal(int k, int l)
{
    if(k == x[1] && l == y[1])
        return 0;

    int up = 9999, down = 9999, left = 9999, right = 9999;

    bool hasPath = false;
    if(k >= 1 && maze[k - 1][l] == '.' && visited[k - 1][l] == '0')
    {
        hasPath = true;
        visited[k - 1][l] = '1';
        up = traversal(k - 1, l);
        visited[k - 1][l] = '0';
    }
    if(k <= n - 2 && maze[k + 1][l] == '.' && visited[k + 1][l] == '0')
    {
        hasPath = true;
        visited[k + 1][l] = '1';
        down = traversal(k + 1, l);
        visited[k + 1][l] = '0';
    }
    if(l >= 1 && maze[k][l - 1] == '.' && visited[k][l - 1] == '0')
    {
        hasPath = true;
        visited[k][l - 1] = '1';
        left = traversal(k, l - 1);
        visited[k][l + 1] = '0';
    }
    if(l <= m - 2 && maze[k][l + 1] == '.' && visited[k][l + 1] == '0')
    {
        hasPath = true;
        visited[k][l + 1] = '1';
        right = traversal(k, l + 1);
        visited[k][l + 1] = '0';
    }

    if(hasPath == false)
        return 9999;

    int min;
    if(up < 9000) min = up;
    if(down < min && down < 9000) min = down;
    if(left < min && left < 9000) min = left;
    if(right < min && right < 9000) min = right;
    return min + 1;
}
