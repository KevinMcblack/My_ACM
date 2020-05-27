#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	unsigned long long int n,x,y,p,kaifang;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld%lld",&x,&y);
		p=y-x;
		if(p<=3)
			printf("%lld\n",p);
		else
			{
				kaifang=sqrt(p);
				if(kaifang*kaifang==p)
					printf("%lld\n",2*kaifang-1);
				else if(kaifang*kaifang+kaifang>=p)
					printf("%lld\n",2*kaifang);
				else if(kaifang*kaifang+kaifang<p)
					printf("%lld\n",2*kaifang+1);
			}
	}
	return 0;
} 