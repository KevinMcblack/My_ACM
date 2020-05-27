#include <stdio.h>
int main(int argc, char *argv[])
{
	int t,n,i,sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		if(n==1)
			printf("1\n");
		else if(n==2)
			printf("3\n");
		else 
			{
				if(n%2==0)
					for(i=n;i>3;i=i-2)
						sum+=2*i;
				else
				{
					sum=sum+n+1; 
					for(i=n-1;i>3;i=i-2)
						sum+=2*i;
				}	
				printf("%d\n",sum+3);	
			}
		
	}
	return 0;
}