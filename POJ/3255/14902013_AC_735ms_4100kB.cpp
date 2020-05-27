#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
const int maxn = 1e5 + 5;
const int maxv = 5e4 + 7;
const int maxe = 2e5 + 7;
#define INF 0x3f3f3f3f
typedef pair<int, int> P;
int E, V;
struct Edge
{
	int to, next, cost;
	Edge() {}
	Edge(int to,int cost,int next):to(to),cost(cost),next(next){}
}edge[maxe];
int head[maxv];
int num = 0;
void add(int from,int to,int cost)
{
	edge[num] = Edge(to, cost, head[from]);
	head[from] = num++;
}
int dijkstra()
{
	int dist1[maxv], dist2[maxe];
	priority_queue<P, vector<P>, greater<P> >q;
	fill(dist1, dist1 + maxv, INF);
	fill(dist2, dist2 + maxe, INF);
	dist1[1] = 0;
	q.push(P(dist1[1],1));
	while (!q.empty())
	{
		P p = q.top();
		q.pop();
		int v = p.second, d = p.first;
		if (dist2[v] < d)
			continue;
		int t = head[v];
		while (t != -1)
		{
			Edge e = edge[t];
			int d2 = e.cost + d;
			if (d2 < dist1[e.to])
			{
				swap(dist1[e.to], d2);
				q.push(P(dist1[e.to],e.to));
			}
			if (d2<dist2[e.to] && d2>dist1[e.to])
			{
				dist2[e.to] = d2;
				q.push(P(dist2[e.to],e.to));
			}
			t = e.next;
		}
	}
	return dist2[V];
}
int main()
{
	cin >> V >> E;
	memset(head, -1, sizeof(head));
	memset(edge, -1, sizeof(edge));
	for (int  i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		add(from, to, cost);
		add(to, from, cost);
	}
	cout << dijkstra() << endl;
	return 0;
}