#include <cstdio>  
#include <algorithm>  
using namespace std;  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1 
#define max(a, b) ((a) > (b) ? (a) : (b))  
#define min(a, b) ((a) < (b) ? (a) : (b)) 
typedef long long ll;
const int maxn = 150000;  
ll MAX[maxn<<2]={0};  
void PushUP(ll rt) {  
    MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);  
}  
void build(ll l,ll r,ll rt) {  
    if (l == r) {  
        //scanf("%d",&MAX[rt]);
        //MAX[rt]=0;
        return ;  
    }  
    ll m = (l + r) >> 1;  
    build(lson);  
    build(rson);  
    PushUP(rt);  
}  
void update(ll p,ll sc,ll l,ll r,ll rt) {  
    if (l == r) {  
        MAX[rt]+= sc;  
        return ;  
    }  
    ll m = (l + r) >> 1;  
    if (p <= m) update(p , sc , lson);  
    else update(p , sc , rson);  
    PushUP(rt);  
}  
ll query(ll L,ll R,ll l,ll r,ll rt) {  
    if (L <= l && r <= R) {  
        return MAX[rt];  
    }  
    ll m = (l + r) >> 1;  
    ll ret = 0;  
    if (L <= m)
		ret = max(ret , query(L , R , lson));  
    if (R > m)
		ret = max(ret , query(L , R , rson));  
    return ret;  
}  
int main() {  
    ll n , m;  
    scanf("%lld%lld",&n,&m);

        build(1 , n , 1);  
        while (m --)
		{  
            ll op;  
            ll a , b;  
            scanf("%lld%lld%lld",&op,&a,&b);  
            if (op == 2)
				printf("%lld\n",query(a , b , 1 , n , 1));  
            else 
				update(a , b , 1 , n , 1);  
        }  
     
    return 0;  
}  