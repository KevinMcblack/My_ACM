#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	long long int n,m,k,sum;
	int i,j;
	while(scanf("%lld",&n)!=EOF&&n)
	{
		m=sqrt(n);
		//printf("%lld\n",m);
		if(m*m==n)
			k=m;
		else
			k=m+1;
		sum=1;
		j=0;
		for(i=0;;i=i+2)
		{
			sum+=i;
			j++;
			if(j==k)
				break;
		}
		//printf("%lld\n",sum);
		if(k%2!=0)
		{
			if(n>sum)
				printf("%lld %lld\n",k-(n-sum),k);
			else if(n==sum)
				printf("%lld %lld\n",k,k);
			else
				printf("%lld %lld\n",k,k-(sum-n));
		}
		else
		{
			if(n>sum)
				printf("%lld %lld\n",k,k-(n-sum));
			else if(n==sum)
				printf("%lld %lld\n",k,k);
			else
				printf("%lld %lld\n",k-(sum-n),k);
		}	
		
	}
	return 0;
}