#include <stdio.h>
int main(int argc, char *argv[])
{
	int n,count;
	unsigned long long int num;
	while(scanf("%d",&n)!=EOF)
	{
		num=1;
		count=1;
		while(num%n)
		{
			num=(num%n)*(10%n)+1;
			count++;
		}
		printf("%d\n",count);
	}
	return 0;
}