#include <iostream>  
#include <algorithm>
using namespace std;
struct smallest{
	int a,b;
}c[100010];
bool cmp(smallest aa, smallest bb)  
{  
    return aa.b < bb.b;  
} 
int main(int argc, char *argv[])
{
	int t,n,i,j;
	struct smallest temp;
	long long casee=0,max=0,sum=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&c[i].a,&c[i].b);
		sort(c,c+n,cmp);
		max=0;
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=c[i].a;
			if(max<sum-c[i].b)
				max=sum-c[i].b;
		}
		printf("Case %I64d: %I64d\n",++casee,max);
	}
	return 0;
}