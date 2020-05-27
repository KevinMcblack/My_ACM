#include <stdio.h>
struct elephant{
	int number;
	int a;
	int b;
}c[1050];

int dp[1050],out[1050];  
//递归逆序输出 
int print(int x)  
{  
    if(out[x]!=x)  
        print(out[x]);  
    printf("%d\n",c[x].number); 
}  
int main(int argc, char *argv[])
{
	int i=0,j=0,n=0;
	struct elephant temp;
	c[0].number=0;
	while(scanf("%d%d",&c[i].a,&c[i].b)!=EOF&&c[i].a||c[i].b)
	{
		c[i].number++;
		c[i+1].number=c[i].number;
		i++;
		n++;
	}
	//按体重排序 
	for(i=0;i<n;i++)
		for(j=0;j<n-1;j++)
			if(c[j].a>c[j+1].a)
			{
				temp=c[j];
				c[j]=c[j+1];
				c[j+1]=temp;
			}
	//测试数据 
//	for(i=0;i<n;i++)
//		printf("%d %d %d\n",c[i].number,c[i].a,c[i].b);
	 for(i=1;i<n;i++)  
    {  
        dp[i]=1; 
		out[i]=i; 
       	//printf("%d %d %d\n",c[i].a,c[i].b,c[i].number);  
        for(j=1;j<i;j++)  
        {  
            if(c[i].a>c[j].a&&c[i].b<c[j].b&&dp[j]+1>dp[i])  
            {  
                dp[i]=dp[j]+1;  
                out[i]=j;
            }  
        }  
    }  
    int ans=0,p=0;
    //for(i=1;i<n;i++) 
//    {
//    	printf("dp:%d out:%d\n",dp[i],out[i]);
//    }
    for(i=1;i<n;i++)  
    {  
        if(dp[i]>ans)
        {
        	ans=dp[i];
			p=i;
        }       
    }  
    printf("%d\n",ans); 
	//printf("p:%d\n",p); 
    print(p);
	return 0;
}