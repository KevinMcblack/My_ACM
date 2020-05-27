#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
struct node{
	int x,y;
}a[100000];
bool use[6000];
bool cmp(struct node aa,struct node bb)
{
	if(aa.x==bb.x)
		return aa.y<bb.y;
	return aa.x<bb.x;
}
int main(int argc, char *argv[])
{
	int t,n,j;
	scanf("%d",&t);
	while(t--)
	{
		memset(use, 0, sizeof(use));
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		sort(a,a+n,cmp);
		int count=0;
		struct node last;
		for(i=0;i<n;i++)
		{
			last.y=a[i].y;
			if(!use[i])
			{
				for(j=i+1;j<n;j++)
					if(last.y<=a[j].y&&!use[j])
					{
						use[j]=1;
						last.y=a[j].y;
					}
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}