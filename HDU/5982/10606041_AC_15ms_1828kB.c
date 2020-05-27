#include<stdio.h>  
int main()  
{   int t,a,b,sum,n;  
    scanf("%d",&t);  
    while(t--)  
    {  
      scanf("%d",&n);  
      sum=0;  
      while(n--)  
      {  
          scanf("%d%d",&a,&b);  
          sum+=a*b;  
      }  
        printf("%d\n",sum);  
    }  
    return 0;  
}  