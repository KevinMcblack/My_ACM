#include <stdio.h> 
#define min(a,b) (a)<(b)?(a):(b) 
int main(int argc, char *argv[])
{
	int t,number,i,j,a[1005],temp,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&number);
		for(i=1;i<=number;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=number;i++)
			for(j=1;j<=number-1;j++)
				if(a[j]>a[j+1])
					{
						temp=a[j+1];
						a[j+1]=a[j];
						a[j]=temp;
					}
		if(number==1)
			printf("%d\n%d\n",a[1],a[1]);
		else if(number==2)
			printf("%d\n%d %d\n",a[2],a[1],a[2]);
		else
			{
				sum=a[2];
				for(i=number-2;i>1;i=i-2)
					sum+=min(a[i+2]+a[2]*2+a[1],a[i+2]+a[i+1]+a[1]*2);
				if(number%2)
					sum+=a[1]+a[3];
				printf("%d\n",sum);
				for(i=number-2;i>1;i=i-2) 
		        if(a[i+2]+a[2]*2+a[1]<a[i+2]+a[i+1]+a[1]*2)
		            printf("%d %d\n%d\n%d %d\n%d\n", a[1],a[2],a[1],a[i+1],a[i+2],a[2]);  
		        else 
		            printf("%d %d\n%d\n%d %d\n%d\n", a[1],a[i+2],a[1],a[1],a[i+1],a[1]);  
			    if(number%2)  
			        printf("%d %d\n%d\n", a[1],a[3],a[1]);
			    printf("%d %d\n",a[1],a[2]);
			}
		if(t)
			printf("\n");			
	}
	return 0;
}