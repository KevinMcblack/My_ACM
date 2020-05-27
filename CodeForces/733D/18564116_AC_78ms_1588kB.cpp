#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
    int id;
    int a,b,c;
}a[100005];

bool cmp(node a,node b)
{
    if(a.a==b.a)
    {
        if(a.b==b.b)
        {
            return a.c>b.c;
        }
        else
        {
            return a.b>b.b;
        }
    }else{
        return a.a>b.a;
    }
}
int w[5];
int main(int argc, char *argv[])
{
    int n;
    int maxn=0;
    int ans1;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&w[0],&w[1],&w[2]);
            sort(w,w+3);
            a[i].a=w[2];
            a[i].b=w[1];
            a[i].c=w[0];
            a[i].id=i;
            if(maxn<a[i].c)
            {
                maxn=a[i].c;
                ans1=i;
            }
        }
        sort(a+1,a+n+1,cmp);
        int ans2=-1;
        for(int i=1;i<n;i++)
        {
            if(a[i].a==a[i+1].a&&a[i].b==a[i+1].b)
            {
                w[0]=a[i].c+a[i+1].c;
                w[1]=a[i].a;
                w[2]=a[i].b;
                sort(w,w+3);
                if(w[0]>maxn)
                {
                    maxn=w[0];
                    ans2=a[i].id;
                    ans1=a[i+1].id;
                }
            }
        }
        if(ans2==-1)
        {
            printf("%d\n%d\n",1,ans1);
        }else{
            printf("%d\n%d %d\n",2,ans1,ans2);
        }
    }
    return 0;
}