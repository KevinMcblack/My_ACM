#include <stdio.h>
int main(int argc, char *argv[])
{
	unsigned long long int m,n;
	int count,c;
	while(scanf("%lld%lld",&m,&n)!=EOF)
	{
		if(m>0||n>0)
		{
		count=0;
		c=0;
		while(m!=0||n!=0) 
		{	
			if((m%10+n%10+c)>9)
				{
					c=1;
					count++;
				}
			else
				{
					c=0;
				}
			m/=10;
			n/=10;		
		}
		if(count==0)
			printf("No carry operation.\n");
		else if(count==1)
			printf("%d carry operation.\n",count);	
		else
			printf("%d carry operations.\n",count);		
		}
		else
			break;
	}
	return 0;
}