#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
#define maxn 1000  
#define inf 0x3f3f3f3f  
  
using namespace std;  
  
struct edge//数据结构  
{  
    int en,flow,rev;  
};  
  
vector <edge> v[maxn];  
int vis[maxn];  
  
void addedge(int st,int en,int flow)//加边  
{  
    edge save;  
    save.en=en;save.flow=flow;save.rev=v[en].size();  
    v[st].push_back(save);  
    save.en=st;save.flow=0;save.rev=v[st].size()-1;  
    v[en].push_back(save);  
    return;  
}  
  
int dfs(int st,int en,int flow)  
{  
    if (st==en) return flow;  
    vis[st]=1;  
    for (int k=0;k<v[st].size();k++)  
    {  
        edge &save=v[st][k];  
        if ((!vis[save.en])&&(save.flow>0))  
        {  
            int d=dfs(save.en,en,min(flow,save.flow));  
            if (d>0)  
            {  
                save.flow-=d;  
                v[save.en][save.rev].flow+=d;  
                return min(flow,d);  
            }  
        }  
    }  
    return 0;  
}  
  
int max_flow(int st,int en)//求最大流  
{  
    int sum(0);  
    while(1)  
    {  
        memset(vis,0,sizeof(vis));  
        int flow(0);  
        flow=dfs(st,en,inf);  
        if (flow<=0) break;  
        else sum+=flow;  
    }  
    return sum;  
}  
  
int main()  
{  
    int n,t,m,Case;  
    Case=0;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d %d",&m,&n);  
        for (int k=1;k<=n;k++)  
            v[k].clear();  
  
        for (int k=1;k<=n;k++)  
        {  
            int st,en,flow;  
            scanf("%d %d %d",&st,&en,&flow);  
            addedge(st,en,flow);  
        }  
        Case++;  
        printf("Case %d: %d\n",Case,max_flow(1,m));  
    }  
    return 0;  
}  