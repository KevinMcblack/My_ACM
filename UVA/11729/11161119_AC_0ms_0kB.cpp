#include <iostream>
#include <algorithm>
using namespace std;
struct soldier{
	int ready;
	int use;
}a[1500];
bool cmp(struct soldier aa,struct soldier bb)
{
	return aa.use>bb.use;	
}
int main(int argc, char *argv[])
{
	int n,sum,count=0,ans;
	while(scanf("%d",&n)!=EOF&&n)
	{
		count++;
		sum=0,ans=0;
		int i;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].ready,&a[i].use);
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		{
			sum+=a[i].ready;
			if(sum+a[i].use>ans)
				ans=sum+a[i].use;
		}
		printf("Case %d: %d\n",count,ans);
	}
	return 0;
}