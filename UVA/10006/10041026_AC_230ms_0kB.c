#include <stdio.h>
#include <math.h>
int isPri(int n)
{
	int i;
    for(i=2;i<=sqrt(n);i++)  
        if(n%i == 0) 
            return 0; 
    return 1;  
} 
long long powmod(int a, int p, int n)
{  
    if(p==1) 
        return a%n;  
    if(p==0)
        return 1%n; 
    return (powmod(a,p/2,n)%n)*(powmod(a,p/2,n)%n)*(powmod(a,p%2,n)%n)%n;  
} 
int isCar(int n)
{  
	long long a;
    if(isPri(n)) 
        return 0;  
    for(a=2;a<n;a++) 
        if(powmod(a,n,n)!=a)
            return 0;  
    return 1;  
}
int main(int argc, char *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		else
		{
			if(isCar(n))
				printf("The number %d is a Carmichael number.\n",n);
			else
				printf("%d is normal.\n",n);		
		}
	} 
	return 0;
}