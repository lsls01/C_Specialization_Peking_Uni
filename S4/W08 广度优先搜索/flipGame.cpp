#include<stdio.h>
#include<string.h>
int map[10][10],step,flag=0;
int dx[5]={0,0,0,-1,1};
int dy[5]={1,-1,0,0,0};
int jud()
{
    int i,j;
    for(i=1;i<=4;i++)
        for(j=1;j<=4;j++)
        {
            if(map[i][j]!=map[1][1])
                return 0;
        }
    return 1;
}
void fun(int x,int y)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        int fx=x+dx[i];
        int fy=y+dy[i];
        map[fx][fy]=!map[fx][fy];
    }
}
void dfs(int x,int y,int cnt)
{
    if(cnt==step)
    {
        flag=jud();
        return;
    }
    if(flag)
        return;
    if(x==5)
        return;
    fun(x,y);
    if(y<4)
        dfs(x,y+1,cnt+1);
    else
        dfs(x+1,1,cnt+1);
    fun(x,y);
    if(y<4)
        dfs(x,y+1,cnt);
    else
        dfs(x+1,1,cnt);
}
int main()
{
    int i,j;
    char c;
    for(i=1;i<=4;i++)
    {
        for(j=1;j<=4;j++)
        {
            scanf("%c",&c);
            if(c=='b')
                map[i][j]=1;
        }
        getchar();
    }
    for(step=0;step<=16;step++)
    {
        dfs(1,1,0);
        if(flag)
            break;
    }
    if(flag)
        printf("%d\n",step);
    else
        printf("Impossible\n");
}
