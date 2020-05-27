#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))  
#define min(a, b) ((a) < (b) ? (a) : (b))
int main(int argc, char *argv[])
{
	int n,k,a[20050],b[20050],t[20050],dp[20050],i,j;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&t[i],&a[i],&b[i]);
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
	{
		if(t[i]==2)
			for(j=k;j>=b[i];j--)
			{
				dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
			}
		else
			for(j=b[i];j<=k;j++)
		    {
		        dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
		    }
	}
	printf("%d\n",dp[k]);
	return 0;
}