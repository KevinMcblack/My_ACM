#include<iostream>     
using namespace std;  
const int N=100005;  
typedef long long ll;  
ll t[N<<2],ladd[N<<2],lmul[N<<2],n,p,m;  
void build(ll l,ll r,ll rt)//l,r表示当前节点区间，rt表示当前节点编号 
{  
    lmul[rt]=1,ladd[rt]=0;  
    if(l==r)//若到达叶节点 
    {  
        scanf("%lld",&t[rt]);  
        return;  
    }  
    ll m=(l+r)>>1; 
	//左右递归 
    build(l,m,rt<<1);  
    build(m+1,r,rt<<1|1); 
	//更新信息 
 	t[rt]=(t[rt<<1]+t[rt<<1|1])%p;  
}  
void pushdown(ll rt,ll num)  
{  
    ladd[rt<<1]=(ladd[rt<<1]*lmul[rt]+ladd[rt])%p;  
    ladd[rt<<1|1]=(ladd[rt<<1|1]*lmul[rt]+ladd[rt])%p;  
    lmul[rt<<1]=(lmul[rt<<1]*lmul[rt])%p;  
    lmul[rt<<1|1]=(lmul[rt<<1|1]*lmul[rt])%p;  
    t[rt<<1]=(t[rt<<1]*lmul[rt]+(num-num/2)*ladd[rt])%p;  
    t[rt<<1|1]=(t[rt<<1|1]*lmul[rt]+(num/2)*ladd[rt])%p;  
    ladd[rt]=0;  
    lmul[rt]=1;  
}  
void updata(ll x,ll y,ll l,ll r,ll rt,ll val,ll op)  
{  
    if(x<=l&&r<=y)  
    {  
        if(op==1)  
        {  
            ladd[rt]=(ladd[rt]*val)%p;  
            lmul[rt]=(lmul[rt]*val)%p;  
            t[rt]=(t[rt]*val)%p;  
        }  
        else  
        {  
            ladd[rt]=(ladd[rt]+val);  
            t[rt]=(t[rt]+(r-l+1)*val)%p;  
        }  
        return;  
    }  
    pushdown(rt,r-l+1);  
    ll m=(l+r)>>1;  
    if(x<=m)  
        updata(x,y,l,m,rt<<1,val,op);  
    if(y>m)  
        updata(x,y,m+1,r,rt<<1|1,val,op);  
    t[rt]=(t[rt<<1]+t[rt<<1|1])%p;  
}  
ll query(ll x,ll y,ll l,ll r,ll rt)  
{  
    if(x<=l&&y>=r)  
       return t[rt]%p;  
    pushdown(rt,r-l+1);  
    ll m=(l+r)>>1;  
    ll res=0;  
    if(x<=m)  
        res+=query(x,y,l,m,rt<<1);  
     if(y>m)  
      res+=query(x,y,m+1,r,rt<<1|1);  
        return res%p;  
}  
int main()  
{  
    scanf("%lld%lld",&n,&p);  
    build(1,n,1);  
    scanf("%lld",&m);  
    ll x,y,val,op;  
    for(ll i=0;i<m;i++)  
    {  
        scanf("%lld",&op);  
        if(op==1)  
        {  
            scanf("%lld%lld%lld",&x,&y,&val);  
            updata(x,y,1,n,1,val,1);  
        }  
        else if(op==2)  
        {  
            scanf("%lld%lld%lld",&x,&y,&val);  
            updata(x,y,1,n,1,val,2);  
        }  
        else  
        {  
            scanf("%lld%lld",&x,&y);  
            printf("%lld\n",query(x,y,1,n,1));  
        }  
    }  
}  