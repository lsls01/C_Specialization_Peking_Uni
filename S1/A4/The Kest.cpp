#include<iostream>
#include<iomanip>
using namespace std;

int function(int n,int k)
{
    int p;
    int b;
    int a[100];
    int i;
    int j;
    for(i=0;i<n;i++)
        cin >> a[i];
 
    for(i=0;i<n;i++)
    {
        p=0;
        for(j=0;j<n;j++)        
        {
            if(i!=j&&a[j]>a[i])
                p++;
            if(p>=k)//�Ѿ��ж���k������a[i]��
                break;
        }
        if(j==n&&p==k-1)//�������������飬������k-1������a[i]������a[i]���ǵ�K�����
        {
            b=a[i];
            break;
        }
    }
    return b;
}
 
int main()
{
    int n;
    int k;
    cin >> n >> k;
    cout << function(n,k) << endl;
    return 0;
}