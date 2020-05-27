#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
const int maxn = 5e2 + 5;
const int maxv = 2e4 + 7;
const int maxe = 2e6 + 7;
#define INF 0x3f3f3f3f
typedef pair<int, int> P;
int n, m,w,num;
int head[maxn];
int dis[maxn], cnt[maxn];
bool vis[maxn];

struct Edge
{
	int to, next, cost;
}edge[maxn*10];
void add(int from, int to, int cost)
{
	edge[num].cost = cost;
	edge[num].to = to;
	edge[num].next = head[from];
	head[from] = num++;
}
void init()
{
	num = 0;
	memset(head,-1,sizeof(head));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(dis, INF, sizeof(cnt));
}
int spfa()
{
	queue<int>q;
	cnt[1]=1;
	dis[1] = 0;
	vis[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].to;
			int c = edge[i].cost;
			if (dis[v] > dis[u] + c)
			{
				dis[v] = dis[u] + c;
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
					cnt[v]++;
					if (cnt[v] > n)
						return 0;
				}
			}
		}
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cas;
	cin >> cas;
	while (cas--)
	{
		int u, v, t;
		init();
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> t;
			add(u,v,t);
			add(v, u, t);
		}
		for (int i = 0; i < w; i++)
		{
			cin >> u >> v >> t;
			add(u, v, -t);
		}
		if (spfa())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}