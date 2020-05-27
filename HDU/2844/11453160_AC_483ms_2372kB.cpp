#include <iostream>  
#include <stdio.h>  
#include <string.h>  
using namespace std;  
  
int use[100001],a[100005]; 
int n,m;  
bool dp[100001];  
int num[1001];  
int main()   
{  
    while (scanf("%d %d", &n, &m) != EOF)   
    {  
        if (n == 0 && m == 0) break;  
        for (int i = 0; i < n; ++i)  
            scanf("%d", a+i);  
        for (int i = 0; i < n; ++i)   
            scanf("%d", num+i);  
        int res = 0;  
        memset(dp,false,sizeof(dp));  
        dp[0] = true;  
        for (int i = 0; i < n; ++i)   
        {  
            memset(use,0,sizeof(use));  
            for (int j = a[i]; j <= m; ++j)   
            {  
                if (!dp[j] && dp[j-a[i]] && use[j-a[i]]<num[i])  
                {  
                    dp[j] = true;  
                    use[j] = use[j-a[i]] + 1;  
                    ++res;  
                }  
            }  
        }  
        printf("%d\n", res);  
    }  
 	return 0;  
}  