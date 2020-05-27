#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 2002;
int dis[maxn], pre[maxn];

struct Edge //边
{
    int u, v, w;
    Edge(){};
    Edge(int uu, int vv, int ww) : u(uu), v(vv), w(ww){};
};

vector<Edge> edges;  //边数组
vector<int> G[maxn]; //存储每个节点对应的边的序号

void init(int nn) //清理
{
    for (int i = 0; i <= nn; i++)
        G[i].clear();
    edges.clear();
}

void AddEdge(int uu, int vv, int ww) //加边
{
    edges.push_back(Edge(uu, vv, ww));
    int edgenum = edges.size();
    G[uu].push_back(edgenum - 1);
}

struct node //优先队列优化，dis小的先出队
{
    int u, d;
    node(){};
    node(int uu, int dd) : u(uu), d(dd){};
    friend bool operator<(node a, node b)
    {
        return a.d > b.d;
    }
};

void dijkstra(int s)
{
    priority_queue<node> q;
    memset(dis, INF, sizeof(dis)); //dis初始化为INF
    dis[s] = 0;
    q.push(node(s, dis[s]));
    while (!q.empty())
    {
        node cur = q.top();
        q.pop();
        int from = cur.u;
        if (cur.d != dis[from]) //减少了vis数组，表示该节点被取出来过
            continue;
        for (int i = 0; i < G[from].size(); i++) //更新所有集合外点到集合的dis
        {
            Edge e = edges[G[from][i]];
            if (dis[e.v] > dis[e.u] + e.w)
            {
                dis[e.v] = dis[e.u] + e.w;
                pre[e.v] = from;             //存储父节点
                q.push(node(e.v, dis[e.v])); //将有更新的dis加入到队列中
            }
        }
    }
}
int main()
{
    int n, m;
    while (~scanf("%d%d", &m, &n) && n && m)
    {
        init(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            AddEdge(u, v, w);
            AddEdge(v, u, w);
        }
        dijkstra(1);
        printf("%d\n", dis[n]);
    }
    return 0;
}