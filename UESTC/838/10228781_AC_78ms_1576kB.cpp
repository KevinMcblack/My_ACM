#include <stdio.h> 
const int maxn = 100500;  
int c[maxn],a[maxn];  
int lowbit(int x){return x&(-x);}  
void update(int i,int d)  
{  
    while(i<maxn)  
    {  
        c[i]+=d;  
        i+=lowbit(i);  
    }  
}  
int query(int i)  
{  
    int ans = 0;  
    while(i)  
    {  
        ans+=c[i];  
        i-=lowbit(i);  
    }  
    return ans;  
}  
int main()  
{  
    int n,m,i;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        for(i = 1;i<=n;i++)  
           scanf("%d",&a[i]),update(i,a[i]);  
        for(i = 1;i<=m;i++)  
        {  
            int op,a,b;  
            scanf("%d%d%d",&op,&a,&b);  
            if(op==1)  
                update(a,b);  
            else  
                printf("%d\n",query(b)-query(a-1));  
        }  
    }  
} 