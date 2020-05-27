#include <stdio.h>
#define min(a,b) a>b?b:a
int main(int argc, char *argv[])
{
	int m,n;
	scanf("%d%d",&m,&n);
	int i;
	long long a[10050],b[10050],sum=0;
	for(i=0;i<m;i++)
		 scanf("%lld%lld",&a[i],&b[i]);
 	for(i=0;i<m;i++)
	 	a[i+1]=min(a[i]+n,a[i+1]);
 	for(i=0;i<m;i++)
 		sum+=a[i]*b[i];
	printf("%lld\n",sum);
	return 0;
}