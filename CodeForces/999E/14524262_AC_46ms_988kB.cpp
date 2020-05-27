#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>
using namespace std;
const int maxn = 1e4 + 5;
struct edge {
	int to, next;
}Edge[50005];
int head[maxn], low[maxn], dfn[maxn], instack[maxn], stack[maxn];
int belong[maxn];//子强连通图
int in[maxn];
int n, m, edge_num, dindex, stop;
int bcnt;//强连通分量的个数
int s;
void init()
{
	edge_num = stop = bcnt = dindex = 0;
	memset(Edge, -1, sizeof(Edge));
	memset(head, -1, sizeof(head));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(instack, 0, sizeof(instack));
	memset(stack, 0, sizeof(stack));
	memset(belong, 0, sizeof(belong));
	memset(in, 0, sizeof(in));
}
void addedge(int u, int v)
{
	Edge[edge_num].to = v;
	Edge[edge_num].next = head[u];
	head[u] = edge_num;
	edge_num++;
}
void tarjan(int i)
{
	dfn[i] = low[i] = ++dindex;
	instack[i] = true;
	stack[++stop] = i;

	for (int j = head[i]; j != -1; j = Edge[j].next)
	{
		int v = Edge[j].to;
		if (dfn[v] == 0)
		{
			tarjan(v);
			low[i] = min(low[i], low[v]);
		}
		else if (instack[v] == 1)
			low[i] = min(low[i], dfn[v]);
	}
	if (dfn[i] == low[i])
	{
		int j;
		bcnt++;
		do {
			j = stack[stop--];
			instack[j] = false;
			belong[j] = bcnt;
		} while (j != i);
	}
}
void solve()
{
	init();
	cin >> n >> m>>s;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		addedge(u, v);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 1; i <= n; i++)
		for (int j = head[i]; j != -1; j = Edge[j].next)
		{
			int v = Edge[j].to;
			if (belong[i] != belong[Edge[j].to])
			{
				in[belong[v]]++;
			}
		}
	int ans = 0;
	set<int>ss;
	for (int i = 1; i <= n; i++)
		ss.insert(belong[i]);
	set<int>::iterator it;
	for (it = ss.begin(); it != ss.end(); it++)
	{
		if (*it != belong[s])
			if (in[*it] == 0)
				ans++;
	}
	cout << ans << endl;
}
int main()
{
	solve();
	return 0;
}