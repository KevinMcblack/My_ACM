#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int n,a[3010],b[3010],i,j,k,temp;
	while(scanf("%d",&n)!=EOF)
	{
		k=0;
		if(n==1)
			k=1;
		for(i=0;i<3000;i++)
		{
			b[i]=0;
		}	
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
			b[i]=fabs(a[i+1]-a[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n-1;j++)
			{
				if(b[j]>b[j+1])
				{
					temp=b[j+1];
					b[j+1]=b[j];
					b[j]=temp;
				}
			}
		for(i=0;i<n-1;i++)
			{
				if(b[i+1]-b[i]==1)
					k=1;
				else 
					{
						k=0;
						break;
					}
			}
		if(k==1)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}