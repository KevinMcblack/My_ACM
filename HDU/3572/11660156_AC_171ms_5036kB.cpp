#include<stdio.h>
#include<string.h>
#include<queue>
#include<stack>
#include<algorithm>
#define INF 0x7fffff
#define MAX 11000
#define MAXM 1001000
using namespace std;
struct node
{
    int from,to,cap,flow,next;
}edge[MAXM];
int ans,head[MAX];
int cur[MAX];
int vis[MAX];
int dis[MAX];
int sum,n,m;
int sec;//超级汇点
void init()
{
    ans=0;
    memset(head,-1,sizeof(head));
}
void add(int u,int v,int w)
{
    node E1={u,v,w,0,head[u]};
    edge[ans]=E1;
    head[u]=ans++;
    node E2={v,u,0,0,head[v]};
    edge[ans]=E2;
    head[v]=ans++;
}
void getmap()
{
    int i,j,last=-1;
    sum=sec=0;
    int bt,et,time;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&time,&bt,&et);
        sum+=time;
        add(0,i,time);//超级源点连接第i件任务
        for(j=bt;j<=et;j++)
            add(i,n+j,1);//将每件任务与完成这件任务所需要的时间段内的每一天连接
        last=max(last,et);
    }
    sec=n+last+1;
    for(i=1;i<=sec;i++)
        add(n+i,sec,m);//将所有的时间段内的点指向超级汇点
}
int bfs(int beg,int end)
{
    int i;
    memset(vis,0,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    queue<int>q;
    while(!q.empty())
        q.pop();
    vis[beg]=1;
    dis[beg]=0;
    q.push(beg);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(i=head[u];i!=-1;i=edge[i].next)//遍历所有的与u相连的边
        {
            node E=edge[i];
            if(!vis[E.to]&&E.cap>E.flow)//如果边未被访问且流量未满继续操作
            {
                dis[E.to]=dis[u]+1;//建立层次图
                vis[E.to]=1;//将当前点标记
                if(E.to==end)//如果当前点搜索到终点则停止搜索  返回1表示有从原点到达汇点的路径
                    return 1;
                q.push(E.to);//将当前点入队
            }
        }
    }
    return 0;//返回0表示未找到从源点到汇点的路径
}
int dfs(int x,int a,int end)//把找到的这条边上的所有当前流量加上a（a是这条路径中的最小残余流量）
{
    //int i;
    if(x==end||a==0)//如果搜索到终点或者最小的残余流量为0
        return a;
    int flow=0,f;
    for(int& i=cur[x];i!=-1;i=edge[i].next)//i从上次结束时的弧开始
    {
        node& E=edge[i];
        if(dis[E.to]==dis[x]+1&&(f=dfs(E.to,min(a,E.cap-E.flow),end))>0)//如果
        {//bfs中我们已经建立过层次图，现在如果 dis[E.to]==dis[x]+1表示是我们找到的路径
        //如果dfs>0表明最小的残余流量还有，我们要一直找到最小残余流量为0
            E.flow+=f;//正向边当前流量加上最小的残余流量
            edge[i^1].flow-=f;//反向边
            flow+=f;//总流量加上f
            a-=f;//最小可增流量减去f
            if(a==0)
                break;
        }
    }
    return flow;//所有边加上最小残余流量后的值
}
int Maxflow(int beg,int end)
{
    int flow=0;
    while(bfs(beg,end))//存在最短路径
    {
        memcpy(cur,head,sizeof(head));//复制数组
        flow+=dfs(beg,INF,end);
    }
    return flow;//最大流量
}
int main()
{
    int t;
    scanf("%d",&t);
    int k=1;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        getmap();
        printf("Case %d: ",k++);
        if(sum<=Maxflow(0,sec))
            printf("Yes\n\n");
        else
            printf("No\n\n");
    }
    return 0;
}
