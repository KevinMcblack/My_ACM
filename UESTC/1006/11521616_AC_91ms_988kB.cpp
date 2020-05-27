#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

struct node{
    int pos,num;
};
int cmp(node a,node b)
{
    return a.num<b.num;
}
int T,n;
node a[1005];
int pre[1005],dp[1005],rec[1005];
int main( )
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        memset(pre,-1,sizeof(pre));
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i].num);
            a[i].pos=i;
        }
        sort(a,a+n,cmp);
        int ans=0,anspos;
        dp[0]=1;
        for (int i=0;i<n;i++)
        {
            int Max=0;
            for (int j=0;j<i;j++)
            {
                if (a[i].pos>a[j].pos && dp[j]>Max && a[i].num>a[j].num) //注意a[i].num>a[j].num由于排序后可能出现相同的数字连在一起的情况，不满足严格单调递增
                {
                    pre[i]=j;
                    Max=dp[j];
                }
            }
            dp[i]=Max+1;
            if (dp[i]>ans)
            {
                ans=dp[i];
                anspos=i;
            }
        }
        printf("%d ",ans);
        int cnt=0,xx=anspos;
        while (xx!=-1)
        {
            rec[cnt++]=a[xx].num;
            xx=pre[xx];
        }
        for (int i=cnt-1;i>=0;i--)
        {
            printf("%d ",rec[i]);      //每个数字后都要有空格！
        }
        cout<<endl;
    }
    return 0;
}