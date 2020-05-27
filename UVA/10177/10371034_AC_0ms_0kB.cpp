#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int n,i;
	long long sum1,sum2,sum3,sum4,sum5,sum6;
	while(scanf("%d",&n)!=EOF)
	{
		//if(n==1)
//		{
//			printf("1 0 1 0 1 0\n");
//			continue;
//		}
//		else
//		{
			sum1=sum2=sum3=sum4=sum5=sum6=0;
			for(i=1;i<=n;i++)
			{
				sum1+=i*i;
				sum3+=i*i*i;
				sum5+=i*i*i*i;
			} 
			sum2=pow((n*(n+1))/2,2)-sum1;
			sum4=pow((n*(n+1))/2,3)-sum3;
			sum6=pow((n*(n+1))/2,4)-sum5;
			printf("%lld %lld %lld %lld %lld %lld\n",sum1,sum2,sum3,sum4,sum5,sum6);
		//}
	}
	return 0;
}