#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
const int maxn = 5e5 + 5;
const int maxv = 2e4 + 7;
const int maxe = 2e6 + 7;
#define INF 0x3f3f3f3f
typedef pair<int, int> P;
int n, ml, md;
int head[maxe];
int tol = 1, dis[maxn], cnt[maxn];
bool vis[maxn];
struct Edge
{
	int to, next, cost;
}edge[maxe];
void add(int from, int to, int cost)
{
	edge[tol].cost = cost;
	edge[tol].to = to;
	edge[tol].next = head[from];
	head[from] = tol++;
}
int spfa()
{
	for (int i = 2; i < maxn; i++)
		dis[i] = INF;
	queue<int>q;
	cnt[1]++;
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
						return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> ml >> md;
	int from, to, cost;
	memset(head, -1, sizeof(head));
	while (ml--)
	{
		cin >> from >> to >> cost;
		add(from, to, cost);
	}
	while (md--)
	{
		cin >> to >> from >> cost;
		add(from, to, -cost);
	}
	if (spfa())
		cout << -1 << endl;
	else if (dis[n] == INF)
		cout << -2 << endl;
	else
		cout << dis[n] << endl;
	return 0;
}