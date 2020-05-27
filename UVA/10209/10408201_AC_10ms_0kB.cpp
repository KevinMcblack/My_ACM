#include <stdio.h>  
#include <math.h>   
  
#define pi 3.141592653589793
  
int main(){  
    double a,x,y,z;  
    while(scanf("%lf",&a)!=EOF)
	{  
        z=a*a-pi*a*a/6.0-sqrt(3)/4.0*a*a;  
 		y=a*a-pi*a*a/4.0-2.0*z;  
 		x=a*a-4.0*y-4.0*z;  
        printf("%.3lf %.3lf %.3lf\n",x,4*y,4*z);  
    }  
    return 0;  
}  