#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int t,i,a[1050],n,j,sum,min,casee=0;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		min=100000005;
		for(i=1;i<=n;i++)
		{
			sum=0;
			//sum=a[i];
//			if(min>fabs(sum))
//				min=fabs(sum);
			for(j=i;j<=n;j++)
			{
			sum+=a[j];	
			if(min>fabs(sum))
				min=fabs(sum);
			}
				
		}	
		printf("Case %d: %d\n",++casee,min);
	} 
	return 0;
}