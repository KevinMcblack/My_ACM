#include <iostream>
#include <algorithm>
#include <cstring>
#define max(a,b) a>b?a:b
using namespace std;
struct situation{
	int start;
	int end;
	int output;
}a[1000000];
int dp[10000];
bool cmp(struct situation aa,struct situation bb)
{
	return aa.start<bb.start;
}
int main(int argc, char *argv[])
{
	int t,n,rest,i=0;
	scanf("%d%d%d",&t,&n,&rest);
	for(i=0;i<n;i++)
		scanf("%d%d%d",&a[i].start,&a[i].end,&a[i].output);
	sort(a,a+n,cmp);
	int ans=0,sum,j;
	memset(dp,0,sizeof(dp));
	for(i=0;i<n;i++)
	{
		int maxx=0;
		for(j=0;j<i;j++)
			if(a[j].end+rest<=a[i].start&&maxx<dp[j])
				maxx=dp[j];
		dp[i]=maxx+a[i].output;
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}