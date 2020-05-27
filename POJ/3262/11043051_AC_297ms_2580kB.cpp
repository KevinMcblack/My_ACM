#include <iostream>
#include<algorithm>
using namespace std;
struct la
{
	double a,b,c;
}d[200500];
bool cmp(struct la aa,struct la bb)
{
	return aa.c>bb.c;
}
int main(int argc, char *argv[])
{
	int n;
	double temp=0;
	scanf("%d",&n);
	long long i;	
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf",&d[i].a,&d[i].b);
		d[i].c=d[i].b/d[i].a;
		temp+=d[i].b;
	}
	sort(d,d+n,cmp);
	long long  sum=0;
	
	for(i=0;i<n;i++)
	{
		temp-=d[i].b;
		sum+=2*d[i].a*temp;	
	}
	printf("%lld\n",sum);
	return 0;
}