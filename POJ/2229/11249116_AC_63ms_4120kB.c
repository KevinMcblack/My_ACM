#include <stdio.h>  
int s[1000005];  
int main()  
{  
    int n,i;  
    scanf("%d",&n);  
    s[1]=1;  
    s[2]=2;  
    for(i=3;i<=n;i++)  
    {  
        if(i%2)  
            s[i]=s[i-1];  
        else  
        {  
            s[i]=s[i-2]+s[i/2];  
            s[i]%=1000000000;  
        }  
    }  
    printf("%d\n",s[n]);  
    return 0;  
}  