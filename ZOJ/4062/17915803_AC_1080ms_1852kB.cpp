#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
typedef long long ll;
#define INF 0x3f3f3f3f
ll n,m;
ll a[maxn];
ll b[maxn];

bool check(ll mid){
    if(mid==0){
        return true;
    }
    for(int i=0;i<=n;i++){
        b[i]=0;
    }
    for(int i=0;i<n;i++){
        ll num=(a[i]+mid-1)/a[i];
        if(i==n-1&&b[i]>=num){
            break;
        }
        b[i]++;
        if(b[i]<num){
            b[i+1]+=num-b[i];
            b[i]=num;
        }
    }
    ll tmp=0;
    for(int i=0;i<=n;i++){
        tmp+=b[i];
        if(tmp>m){
            return false;
        }
    }
    return true;
}

int main()
{
    int x,k;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        ll l=0,r=1e18;
        ll mid;
        while(l<r){
            mid=(l+r)/2;
            if(check(mid)){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        printf("%lld\n",l-1);
    }
    return 0;
}