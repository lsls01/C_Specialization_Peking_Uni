#include <stdio.h>  
#include <string.h>  
const int MAX_N = 27;  
bool board[MAX_N][MAX_N];  
int res[MAX_N*MAX_N];  
int row, col, total, id;  
  
inline bool isLegal(int r, int c)  
{  
    return 0<=r && 0<=c && r<row && c<col && !board[r][c];  
}  
  
bool getTourPath(int r = 0, int c = 0, int n = 0)//r为字母， c为数字  
{  
    if (n == total) return true;  
    if (!isLegal(r, c)) return false;  
    res[id] = r, res[id+1] = c;//record result  
    board[r][c] = true;//mark  
    ++++id, ++n;  
    if (getTourPath(r-2, c-1, n)) return true;  
    if (getTourPath(r-2, c+1, n)) return true;  
    if (getTourPath(r-1, c-2, n)) return true;  
    if (getTourPath(r-1, c+2, n)) return true;  
    if (getTourPath(r+1, c-2, n)) return true;  
    if (getTourPath(r+1, c+2, n)) return true;  
    if (getTourPath(r+2, c-1, n)) return true;  
    if (getTourPath(r+2, c+1, n)) return true;  
    ----id, --n;  
    board[r][c] = false;//unmark  
    return false;  
}  
  
int main()  
{  
    int T;  
    scanf("%d", &T);  
    for (int t = 1; t <= T; t++)  
    {  
        printf("Scenario #%d:\n", t);  
        scanf("%d %d", &col, &row);  
        memset(board, 0, sizeof(board));  
        total = col*row;  
        id = 0;  
        if (getTourPath())  
        {  
            for (int i = 0; i < id; i += 2)  
            {  
                putchar(char(res[i]+'A'));  
                putchar(char(res[i+1]+'1'));  
            }  
            putchar('\n');  
        }  
        else puts("impossible");  
        putchar('\n');  
    }  
    return 0;  
}  
