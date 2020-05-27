#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
const int maxn = 1e5 + 5;
const int maxv = 2e4 + 7;
const int maxe = 2e6 + 7;
#define INF 0x3f3f3f3f
typedef pair<int, int> P;
int head[maxn];
int dis[maxn];
bool vis[maxn];
int ans;
int n, m, x;
struct Edge
{
	int u, v, w;
	int next;
}edge[maxn];
void add(int u, int v, int w)
{
	edge[ans].u = u;
	edge[ans].v = v;
	edge[ans].w = w;
	edge[ans].next = head[u];
	head[u] = ans++;
}
void init()
{
	ans = 0;
	memset(head,-1,sizeof(head));
	memset(vis, 0, sizeof(vis));
}
int spfa(int sx,int sy)
{
	memset(dis, INF, sizeof(dis));
	queue<int>q;
	dis[sx] = 0;
	vis[sx] = 1;
	q.push(sx);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			int v = edge[i].v;
			int c = edge[i].w;
			if (dis[v] > dis[u] + c)
			{
				dis[v] = dis[u] + c;
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return dis[sy];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x;
	init();
	int a, b, c;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		add(a,b,c);
	}
	int maxx = -INF;
	int ans;
	for (int i = 1; i <= n; i++)
	{
		ans = spfa(i,x) + spfa(x,i);
		maxx = max(ans,maxx);
	}
	cout << maxx << endl;
	return 0;
}