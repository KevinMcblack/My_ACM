#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	int n,m;
	while(scanf("%d",&n)!=EOF&&n)
	{	
        if(n==1)  
        {  
            printf("0 0\n");  
            continue;  
        }
        n=n-1;
        m=ceil((sqrt(12*n+9)-3)/6);
        //printf("%d\n",m);
        //m为层数 
		if(3*m*(m+1)==n)
			printf("%d 0\n",m,0);
		else
		{
			m=m-1;
			n-=3*m*(m+1);
			if (n <= m + 1)
				printf("%d %d\n", m - n + 1,n);  
            else if(n <= 2*(m + 1) )  
            {  
                n -= (m + 1);  
                printf("%d %d\n", -n, m + 1);  
            }  
            else if(n <= 3 * (m + 1))  
            {  
                n -= 2*(m + 1);  
                printf("%d %d\n", -(m + 1), m + 1 - n);  
            }  
            else if(n <= 4*(m + 1) )  
            {  
                n -= 3 * (m + 1);  
                printf("%d %d\n", -(m - n + 1), -n);  
            }  
            else if(n <= 5*(m + 1))  
            {  
                n -= 4*(m + 1);  
                printf("%d %d\n", n, -(m + 1));  
            }  
            else if(n <= 6*(m + 1))  
            {  
                n -= 5*(m + 1);  
                printf("%d %d\n", m + 1, -(m + 1 - n));  
            }  
		}
 		
	}
	return 0;
}