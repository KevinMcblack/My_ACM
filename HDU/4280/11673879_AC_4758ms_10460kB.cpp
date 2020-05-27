#include<stdio.h>
#include<string.h>

#define MAXN 100010  //点
#define MAXM 880010//边
#define inf 0x3f3f3f
using namespace std;

struct E
{
    int from,v,next;
    int cap;
} edge[MAXM];
int num;
int head[MAXN],dis[MAXN],gap[MAXN];
int nn;//代表点的个数

void init()
{
    num=0;
    memset(head,-1,sizeof(head));
}

void addedge(int u,int v,int w)
{
    edge[num].from=u;edge[num].v=v;edge[num].cap=w;
    edge[num].next=head[u];head[u]=num++;
    edge[num].from=v;edge[num].v=u;edge[num].cap=0;
    edge[num].next=head[v];head[v]=num++;
}
void BFS(int start,int end)
{
    memset(dis,-1,sizeof(dis));
    memset(gap,0,sizeof(gap));
    gap[0]=1;
    int que[MAXN];
    int front,rear;
    front=rear=0;
    dis[end]=0;
    que[rear++]=end;
    while(front!=rear)
    {
        int u=que[front++];
        if(front==MAXN)front=0;
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].v;
            if(dis[v]!=-1)continue;
            que[rear++]=v;
            if(rear==MAXN)rear=0;
            dis[v]=dis[u]+1;
            ++gap[dis[v]];
        }
    }
}
int SAP(int start,int end)
{
    int res=0;
    //nn=end+1;
    BFS(start,end);
    int cur[MAXN];
    int S[MAXN];
    int vp=0;
    memcpy(cur,head,sizeof(head));
    int u=start;
    int i;
    while(dis[start]<nn)
    {
        if(u==end)
        {
            int temp=inf;
            int inser;
            for(i=0; i<vp; i++)
                if(temp>edge[S[i]].cap)
                {
                    temp=edge[S[i]].cap;
                    inser=i;
                }
            for(i=0; i<vp; i++)
            {
                edge[S[i]].cap-=temp;
                edge[S[i]^1].cap+=temp;
            }
            res+=temp;
            vp=inser;
            u=edge[S[vp]].from;
        }
        if(u!=end&&gap[dis[u]-1]==0)
            break;
        for(i=cur[u]; i!=-1; i=edge[i].next)
            if(edge[i].cap!=0&&dis[u]==dis[edge[i].v]+1)
                break;
        if(i!=-1)
        {
            cur[u]=i;
            S[vp++]=i;
            u=edge[i].v;
        }
        else
        {
            int min=nn;
            for(i=head[u]; i!=-1; i=edge[i].next)
            {
                if(edge[i].cap==0)continue;
                if(min>dis[edge[i].v])
                {
                    min=dis[edge[i].v];
                    cur[u]=i;
                }
            }
            --gap[dis[u]];
            dis[u]=min+1;
            ++gap[dis[u]];
            if(u!=start)u=edge[S[--vp]].from;
        }
    }
    return res;
}

int main()
{
   int start,end;
    int m;
    int u,v,z;
    int T;
    scanf("%d",&T);

    while(T--)
    {
        init();
        scanf("%d%d",&nn,&m);
        int minx=10000000;
        int maxx=-10000000;
        int x,y;
        for(int i=1;i<=nn;i++)
        {
            scanf("%d%d",&x,&y);
            if(minx>x)
            {
                minx=x;
                start=i;
            }
            if(maxx<x)
            {
                maxx=x;
                end=i;
            }
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&z);
            addedge(u,v,z);
            addedge(v,u,z);
        }
        //n一定是点的总数，这是使用SAP模板需要注意的
        int ans=SAP(start,end);
        printf("%d\n",ans);
    }
    return 0;
}
