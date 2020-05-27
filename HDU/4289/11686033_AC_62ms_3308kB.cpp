#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 11000
#define Mod 10001
using namespace std;
struct E
{
	int to, frm, nxt, cap;
}edge[MAXN << 5];
int head[MAXN], e, n, m, src, des;
int dep[MAXN], gap[MAXN]; //gap[x]=y:说明残留网络中dep[i]=x的个数为y
void addedge(int u, int v, int c)
{
	edge[e].frm = u;
	edge[e].to = v;
	edge[e].cap = c;
	edge[e].nxt = head[u];
	head[u] = e++;
	edge[e].frm = v;
	edge[e].to = u;
	edge[e].cap = 0;
	edge[e].nxt = head[v];
	head[v] = e++;
}
int Q[MAXN];
void BFS(int src, int des)
{
	memset(dep, -1, sizeof(dep));
	memset(gap, 0, sizeof(gap));
	gap[0] = 1;   //说明此时有1个dep[i] = 0
	int front = 0, rear = 0;
	dep[des] = 0;
	Q[rear++] = des;
	int u, v;
	while (front != rear)
	{
		u = Q[front++];
		//cout<<u<<endl;
		front = front%MAXN;
		for (int i = head[u]; i != -1; i = edge[i].nxt)
		{
			//cout<<i<<endl;
			v = edge[i].to;
			if (edge[i].cap != 0 || dep[v] != -1)
				continue;
			Q[rear++] = v;
			rear = rear % MAXN;
			++gap[dep[v] = dep[u] + 1];  //求出各层次的数量
		}
	}
}
int S[MAXN], cur[MAXN];
int SAP()
{
	int res = 0;
	BFS(src, des);
	int  top = 0;
	memcpy(cur, head, sizeof(head));
	int u = src, i;
	while (dep[src] < n)   //n为结点的个数
	{
		if (u == des)
		{
			int temp = INF, inser = n;
			for (i = 0; i != top; ++i)
				if (temp > edge[S[i]].cap)
				{
					temp = edge[S[i]].cap;
					inser = i;
				}
			for (i = 0; i != top; ++i)
			{
				edge[S[i]].cap -= temp;
				edge[S[i] ^ 1].cap += temp;
			}
			res += temp;
			top = inser;
			u = edge[S[top]].frm;
		}

		if (u != des && gap[dep[u] - 1] == 0)//出现断层，无增广路
			break;
		for (i = cur[u]; i != -1; i = edge[i].nxt)//遍历与u相连的未遍历结点
			if (edge[i].cap != 0 && dep[u] == dep[edge[i].to] + 1) //层序关系， 找到允许
				break;

		if (i != -1)//找到允许弧
		{
			cur[u] = i;
			S[top++] = i;//加入路径栈
			u = edge[i].to;//查找下一个结点
		}
		else   //无允许的路径，修改标号 当前点的标号比与之相连的点中最小的多1
		{
			int min = n;
			for (i = head[u]; i != -1; i = edge[i].nxt) //找到与u相连的v中dep[v]最小的点
			{
				if (edge[i].cap == 0)
					continue;
				if (min > dep[edge[i].to])
				{
					min = dep[edge[i].to];
					cur[u] = i;          //最小标号就是最新的允许弧
				}
			}
			--gap[dep[u]];          //dep[u] 的个数变化了 所以修改gap
			++gap[dep[u] = min + 1]; //将dep[u]设为min(dep[v]) + 1, 同时修改相应的gap[]
			if (u != src) //该点非源点&&以u开始的允许弧不存在，退点
				u = edge[S[--top]].frm;
		}
	}
	return res;
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		int s, d;
		scanf("%d%d", &s, &d);
		src = s, des = d + n;
		e = 0;
		memset(head, -1, sizeof(head));
		for (int i = 1; i <= n; ++i)
		{
			int w;
			scanf("%d", &w);
			addedge(i, i + n, w);
		}
		for (int i = 1; i <= m; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			addedge(a + n, b, INF);
			addedge(b + n, a, INF);
		}
		n = 2 * n; //n为点的个数！
		int ans = SAP();
		printf("%d\n", ans);
	}
	return 0;
}