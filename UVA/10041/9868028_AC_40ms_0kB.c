#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int t,mid,number,a[510],i,j,sum,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&number);
		for(i=0;i<number;i++)
			scanf("%d",&a[i]);
		for(i=0;i<number;i++)
			for(j=0;j<number-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
				}
			}
		mid=number/2;
		sum=0;
		for(i=0;i<number;i++)
			sum+=fabs(a[mid]-a[i]);
		printf("%d\n",sum);
	} 
	return 0;
}