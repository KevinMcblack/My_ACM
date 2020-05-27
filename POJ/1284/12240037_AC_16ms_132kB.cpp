#include <stdio.h>  //p是素数，则p有phi(p-1)个原根。
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
	int res=n-1,a=n-1;  
     for(int i=2;i*i<=a;i++){  
         if(a%i==0){  
             res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出   
             while(a%i==0) 
			 	a/=i;  
         }  
     }  
     if(a>1)
	 	res=res/a*(a-1);  
     printf("%d\n",res);
	}
	return 0;
}