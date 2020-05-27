#include <stdio.h>
int main(int argc, char *argv[])
{
   	int n,i,T,a;
	int b=0;
	int c[100010];
    scanf("%d",&T);
    while(T--)
    {
      	b++;
        scanf("%d",&n);
        for(i = 0;i < n;i++)
           	scanf("%d",&c[i]);
       	a = 1;
        for(i = 1;i < n;i++)
           if(c[i] != c[i-1] + 1)
            {
               a= i+1;
               break;
           }
       printf("Case #%d: %d\n",b,a);
    }
    return 0;
}