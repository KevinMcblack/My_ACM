#include <cstdio>
#include <iostream>
#include <cstring>
#define max(a,b) a>b?a:b
//给你一个长度为N的一个序列，然后让你找连续的包含m数的子序列共K个，让其和尽可能的大，求这个最大值。
//dp【i】【j】=max（dp【i-1】【j-m】+sum【j】，dp【i】【j】）表示我们选择以j结尾的一组数纳入进去。
//dp【i】【j】=max（dp【i】【j-1】）表示我们不选择以j结尾的一组数。
using namespace std;
typedef  long long ll;
ll a[10005];
ll sum[10005];
ll dp[5005][5005];
int main()
{
	 int n;
	 int m,k;
	 while(scanf("%d",&n)!=EOF)
	 {
	 	scanf("%d%d",&m,&k);
	 	for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(i<=m)
				sum[i]=sum[i-1]+a[i];
			else
				sum[i]=sum[i-1]+a[i]-a[i-m];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				if(i>=m)
				{
					dp[j][i]=max(dp[j][i-1],dp[j][i]);
					dp[j][i]=max(dp[j-1][i-m]+sum[i],dp[j][i]);
				}
        printf("%lld\n",dp[k][n]);
	 }
	return 0;
}
