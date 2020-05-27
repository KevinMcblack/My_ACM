#include <stdio.h>
int main(int argc, char *argv[])
{
	long long t,n;
	scanf("%lld%lld",&t,&n);
	long long a[100005];
	long long sum=0;
	for(int i=1;i<=t;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=t;i++)
		if(a[i]>=a[n]-1) 
			sum+=(a[i]-a[n]+1);   
	printf("%lld\n",sum-1);
	return 0;
}