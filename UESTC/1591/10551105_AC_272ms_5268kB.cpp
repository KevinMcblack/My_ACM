#include<stdio.h>
#include<string.h>
long long minn,maxn;
struct node
{
	long long max,min,left,right;
};
struct node a[700000];
long long b[200500];
long long max(long long a,long long b)
{
       if(a>b)return a;
       return b;
}
long long min(long long a,long long b)
{
       if(a<b)return a;
       return b;
}
void build(long long left,long long right,int rt)
{
       a[rt].left=left;
       a[rt].right=right;
       if(left==right)
       {
           a[rt].max=a[rt].min=b[left];
             return;
       }
       int mid=(a[rt].left+a[rt].right)>>1;
       build(left,mid,2*rt);
       build(mid+1,right,2*rt+1);
       a[rt].max=max(a[2*rt].max,a[2*rt+1].max);
       a[rt].min=min(a[2*rt].min,a[2*rt+1].min);
}
void query(long long left,long long right,int rt)
{
       if(a[rt].left>=left&&a[rt].right<=right)
       {
              maxn=max(maxn,a[rt].max);
              minn=min(minn,a[rt].min);
              return;
       }
       int mid=(a[rt].left+a[rt].right)>>1;
       if(left>mid)
	   		query(left,right,2*rt+1);
       else if(right<=mid)
	   		query(left,right,2*rt);
       else
       {
       		query(left,mid,2*rt);
         	query(mid+1,right,2*rt+1);
       }
}
int main()
{
       int i,j,k,m,n;
	   long long p,q;
       while(scanf("%d%d",&n,&m)!=EOF)
       {
              for(i=1;i<=n;i++)
			  	scanf("%lld",&b[i]);
              build(1,n,1);
              while(m--)
              {
                     scanf("%lld%lld",&p,&q);
                     maxn=minn=b[p];
                     query(p,q,1);
                     printf("%lld\n",maxn-minn);
              }
       }
       return 0;
}