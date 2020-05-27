#include <stdio.h>
int main(int argc, char *argv[])
{
	long long a,b,i,t,sum1,sum2;
	while(scanf("%I64d%I64d",&a,&b)!=EOF)
	{
		sum1=sum2=0;
		for(i=1;i<=a-1;i++)
		{
			t=(a-1)/(i*i)-i+1;
			if(t<=0)
				break;
			sum1+=t;
		}
		for(i=1;i<=b;i++)
		{
			t=b/(i*i)-i+1;
			if(t<=0)
				break;
			sum2+=t;
		}
		printf("%I64d\n",sum2-sum1);
	}
	return 0;
}
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
	long long a,b;
	long long i,j,k,count;
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		count=0;
		for(i=a;i<=b;i++)
		{
			for(j=1;j<=i;j++)
			{
				for(k=j;k<=i;k++)
				{
					if(j*j*k==i)
						count++;	
				}
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}*/