#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
using namespace std;
const int maxn = 1e6 + 5;
#define IO ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
#define INF 0x3f3f3f3f
char s1[maxn],s2[maxn];
int main()
{
    int x,k;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s1);
        scanf("%s",s2);
        int count=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
            }else{
                if(count){
                    count=0;
                    cnt++;
                }
            }
        }
        if(count){
            cnt++;
        }
        if(cnt==1){
            printf("%lld\n",(n-1)*2);
        }else if(cnt==2){
            printf("6\n");
        }else if(cnt>2){
            printf("0\n");
        }else{
            printf("%lld\n",n*(n+1)/2);
        }
    }
    return 0;
}