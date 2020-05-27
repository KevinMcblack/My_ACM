#include <stdio.h>
int main(int argc, char *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,c,count=0;
		scanf("%I64d%I64d",&a,&b);
		c=a+b;
	
		while(c)
		{
			if(c%10==5)
				count++;
			c=c/10;
		}
		printf("%I64d\n",count);
	}
	return 0;
}