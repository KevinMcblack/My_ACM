#include <iostream>
#include <algorithm> 
using namespace std;
bool cmp(int aa,int bb)
{
	return bb>aa; 
}
int main(int argc, char *argv[])
{
	int n;
	int a[1500],b[1500];
	while(scanf("%d",&n)!=EOF&&n)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		int awin=0,bwin=0;
		int afast=n-1,bfast=n-1;
		int aslow=0,bslow=0;
		for(i=0;i<n;i++)
		{
			if(a[aslow]>b[bslow])
			{
				awin++;aslow++;bslow++;
			}
			else if(a[aslow]<b[bslow])
			{
				bwin++;aslow++;bfast--;
			}
			else
			{
				if(a[afast]>b[bfast])
				{
					awin++;afast--;bfast--;
				}
				else if(a[aslow]<b[bfast])
				{
					bwin++;aslow++;bfast--;
				}
			}
		}
		printf("%d\n",200*(awin-bwin));
	} 
	return 0;
}