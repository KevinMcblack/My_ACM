#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int  main()  
{  
  
    int T;  
    int i,j,k;  
    char a[30];  
    char b[30];  
    char c[30];  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%s%s%s",a,b,c);  
        printf("%s will survive\n",b);  
    }  
  
    return 0;  
}  