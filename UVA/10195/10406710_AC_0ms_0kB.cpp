#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
	double a,b,c,p,s,r;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
		if (a == 0|| b == 0|| c == 0)  
            r = 0; 
  		else
  		{
		  p=(a+b+c)/2;
		  s=sqrt(p*(p-a)*(p-b)*(p-c));
		  r=2*s/(a+b+c);	
		 }
		printf("The radius of the round table is: %.3lf\n",r);	
	}
	return 0;
}