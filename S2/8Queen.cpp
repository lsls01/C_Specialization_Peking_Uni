int Place(int k) 
{   
    int i; extern int x[n];
    for(i=0; i<k-1; i++)
        if( (x[i]==x[k-1]) || (abs(x[i]-x[k-1])==abs(i-k+1)) )
            return false=0;
    return true=1;
} 
NQueens1(int n)
{
    int k, n; extern int x[n];  k=0; x[k]=-1;
    while(k>=0)
    {
        x[k] = x[k] + 1;
        while((x[k]<n) && (!Place(k)))
            x[k]=x[k]+1;　　//如果当前列不满足情况，则判断下一列
                if(x[k]<n)  　　　　　　　　//如果是上文while中的第二个条件不满足而退出while循环，也就是说找到了可以放置的位置
                {
                    if(k<n-1)
                    {
                        k=k+1;
                        x[k]=-1;
                    }　　　　//判断当前行是不是最后一行，如果是最后一行则表明已经找到结果，打印结果
                    else
                        printf(x[0:n-1]);
                }
                else
                    k=k-1;　　　　　　//上文中while因为第一个条件不满足而退出while循环，在这行里没有满足条件的列，那么退回上一行重新选择满足
                        　　　　　　　　　　　　　　　　　　//条件的的列（回溯）
    }
}
