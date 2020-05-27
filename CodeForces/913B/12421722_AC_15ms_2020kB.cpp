#include <iostream>
#include <string.h> 
using namespace std;  
int main()  
{  
    int n,a[1010],vis[1010],i;  
    while(cin>>n)  
    {  
        memset(vis,0,sizeof(vis));  
        for( i=2; i<=n; i++)  
            cin>>a[i],vis[a[i]]=1;
        for( i=n; i>=1;i--)  
            if(!vis[i]) 
                vis[a[i]]++; 
        for(i=1; i<=n; i++)  
            if(vis[i]&&vis[i]<4) 
                break;  
        if(i>n)  
            puts("Yes");  
        else   puts("No");  
    }  
    return 0;  
}  