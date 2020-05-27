#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))  
#define min(a, b) ((a) < (b) ? (a) : (b))
struct wugui{
	int weight;
	int power;
	//int b;
}a[5650];
int main(int argc, char *argv[])
{
	struct wugui temp;
	int i,j,n=0,imax=0,dp[5650];
	i=0; 
	while(scanf("%d%d",&a[i].weight,&a[i].power)!=EOF&&a[i].weight||a[i].power)
	{
		//a[i].b=a[i].power-a[i].weight;
		i++;
		n++;
	}	
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(a[j].power>a[j+1].power)
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
	memset(dp,0x7f,sizeof(dp));  
    dp[0]=0;  
    for(i=0;i<n;i++)  
    {  
        for(j=imax;j>=0;j--)  
        {  
            if(dp[j]+a[i].weight<a[i].power&&dp[j+1]>dp[j]+a[i].weight)  
            {  
                dp[j+1]=dp[j]+a[i].weight;  
                imax=max(imax,j+1);  
            }  
        }  
    }  
    printf("%d\n",imax);  
//	max=a[0].b;
//	for(i=0;i<n;i++)
//		if(max<a[i].b)
//			max=a[i].b;
	//for(i=0;i<n;i++)
//		printf("%d\n",a[i].b);
	//printf("max:%d\n",max);
	//for(i=0;i<n;i++)
//		printf("%d %d\n",a[i].weight,a[i].power);
	return 0;
}