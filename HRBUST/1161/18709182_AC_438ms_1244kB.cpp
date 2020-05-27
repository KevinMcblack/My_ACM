#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=100002;
int c[maxn];//保存数组中某一段区间的和
int d[maxn];//保存每个保护盾最后一次无效攻击发生在第几秒
int n,q,t;
char cm[10];//命令
int number;//被攻击的编号
 
int lowbit(int x)
{
    return x&(-x);
}
 
void update(int x,int rt)
{
    while(x<=n)
    {
        c[x]+=rt;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}
 
int main()
{
    int k;cin>>k;
    for(int ti=1;ti<=k;ti++)
    {
        cout<<"Case "<<ti<<":"<<endl;
        scanf("%d%d%d",&n,&q,&t);
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        int a,b;
        int attacknum=0;
        for(int i=1;i<=q;i++)
        {
            scanf("%s",cm);
            if(cm[0]=='A')
            {
                attacknum++;
                scanf("%d",&number);
                if(d[number]==0)
                {
                    d[number]=attacknum;
                }
                else
                {
                    if(d[number]+t>attacknum)
                        update(number,1);
                    else
                        d[number]=attacknum;
                }
            }
            if(cm[0]=='Q')
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",sum(b)-sum(a-1));
            }
        }
    }
    return 0;
}
