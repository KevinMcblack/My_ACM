#include <stdio.h>
struct tree  
{  
    unsigned long long int m;  
    unsigned long long int n;  
};
int main()  
{  
    unsigned long long int  up, down;  
    struct tree left, right, middle;  
      
    while(scanf("%lld%lld",&up,&down)!=EOF)  
    {  
    	if(up-down==0)
    		break;
   		else
   			{
			 	left.m = 0;  
		        left.n = 1;  
		
		        right.m = 1;  
		        right.n = 0;  
		      
		        middle.m = 1;  
		        middle.n = 1;  
		          
		        while(1)  
		        {             
		            if (up*middle.n==down*middle.m)  
		                break;  
		            if (up*middle.n>down*middle.m)  
		            {  
		                printf("R");  
		                left.m = middle.m;  
		                left.n = middle.n;  
		                middle.m = (left.m + right.m);  
		                middle.n = (left.n + right.n);  
		            }  
		            else  
		            {  
		                printf("L");  
		                right.m =  middle.m;  
		                right.n = middle.n;  
		                middle.m = (left.m + right.m);  
		                middle.n = (left.n + right.n);              
		            }  
		        }  
		        printf("\n");  	
		   	}
        
    }  
	return 0;
}