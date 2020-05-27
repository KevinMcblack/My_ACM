#include <stdio.h>
int main(int argc, char *argv[])
{
	long long num,k,p,bit,sum,number;
	while(scanf("%lld",&num)!=EOF&&num)
	{
		number=num;
		k=0;
		bit=1;
		sum=0;
		while(num)
		{
			p=num%10;
			if(p>3)
				p-=1;
			sum+=p*bit;
			bit*=9;
			num/=10;
		}
		printf("%lld: %lld\n",number,sum);
	}
	return 0;
}