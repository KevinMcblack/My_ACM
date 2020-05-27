#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	unsigned long long int n,i,count;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n==0)
			break;
		else{
			count=sqrt(n);	
			if(count*count==n)
				printf("yes\n");
			else	
				printf("no\n");
		}
		
	}
	return 0;
}