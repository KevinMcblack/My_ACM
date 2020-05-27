#include<stdio.h>
#include<string.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 1000
int num[N+10],w[N+10],v[N+10];
int main()
{
    int i, j;
    int t, n, V;
    scanf("%d",&t);
    while( t --)
    {
        memset(num,0,sizeof(num));
        scanf("%d%d",&n,&V);
        for(i = 1; i <= n; i ++)
            scanf("%d",&w[i]);
        for( i = 1; i <= n; i ++)
            scanf("%d",&v[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=V;j>=v[i];j--)
            {
                num[j]=max(num[j],num[j-v[i]]+w[i]);
            }
        }
        printf("%d\n",num[V]);
    }
    return 0;
}