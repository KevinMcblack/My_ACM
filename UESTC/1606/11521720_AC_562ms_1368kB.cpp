#include <iostream>  
#include <cstdio>  
#include <cstring>
using namespace std;
const int maxn = 40010;
int n, k;
int dp[maxn], t[maxn], a[maxn], b[maxn];
int main()
{
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        scanf("%d %d %d", &t[i],&a[i],&b[i]);
    }
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; i++){
        if(t[i]==1){
            for(int j=0; j<=k; j++){
                if(j-b[i]>=0){
                    dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
                }
            }
        }
        else{
            for(int j=k; j>=0; j--){
                if(j-b[i]>=0){
                    dp[j]=max(dp[j], dp[j-b[i]]+a[i]);
                }
            }
        }
    }
    printf("%d\n", dp[k]);
    return 0;
}