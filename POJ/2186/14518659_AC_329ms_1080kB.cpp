#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 1e4 + 5;
struct edge {
	int to, next;
}Edge[50005];
int head[maxn], low[maxn], dfn[maxn], instack[maxn], stack[maxn], belong[maxn], out[maxn];
int n, m, edge_num, dindex, stop, bcnt;
void init()
{
	edge_num = stop = bcnt = dindex = 0;
	memset(Edge,-1,sizeof(Edge));
	memset(head, -1, sizeof(head));
	memset(low,0,sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(instack, 0, sizeof(instack));
	memset(stack, 0, sizeof(stack));
	memset(belong, 0, sizeof(belong));
	memset(out, 0, sizeof(out));
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
		} while (j!=i);
	}
}
void solve()
{
	init();
	cin >> n >> m;
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
			if (belong[i] != belong[Edge[j].to])
				out[belong[i]]++;
		}
	int out_num = 0, import;
	for (int i = 1; i <= bcnt; i++)
	{
		if (!out[i])
		{
			out_num++;
			import = i;
		}
	}
	int temp = 0;
	if (out_num == 1)
	{
		for (int i = 1; i <= n; i++)
			if (belong[i] == import)
				temp++;
		cout << temp << endl;
	}
	else
		cout << 0 << endl;
}
int main()
{
	solve();
	return 0;
}
