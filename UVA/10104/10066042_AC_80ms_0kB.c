#include <stdio.h>
#include <math.h>
long long gcd(long long a,long long b,long long *x,long long *y)  
{  
    long long tx,ty;  
    long long g;    
    if (b>a)  
        return gcd(b,a,y,x);   
    if (b==0)  
    {  
        *x=1;  
        *y=0;       
        return a;  
    }  
    g=gcd(b,a%b,&tx,&ty);  
    *x=ty;  
    *y=tx-floor(a/b)*ty;   
    return g;  
}  
int main(int argc, char *argv[])
{
	long long int a,b,g,x,y;
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		g = gcd(a, b, &x, &y); 
		printf("%lld %lld %lld\n",x,y,g);
	}
	return 0;
}