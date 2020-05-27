#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
const int maxn = 5e5 + 5;
const int maxv = 5e4 + 7;
const int maxe = 2e5 + 7;
#define INF 0x3f3f3f3f
int n, m, r;
int father[maxn];
struct node
{
	int x, y, d;
}map[maxn];
bool cmp(node a,node b)
{
	return a.d > b.d;
}
void init() 
{
	int i;
	for (int i = 0; i < maxn; i++)
		father[i] = i;
}
int find(int p)
{
	if (father[p] == p)
		return p;
	return father[p] = find(father[p]);
}
int unite(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if (x != y)
	{
		father[y] = x;
		return 1;
	}
	return 0;
}
int kruskal()
{
	sort(map, map + r, cmp);
	int ans = 0;
	for (int i = 0; i < r; i++)
		if (unite(map[i].x, map[i].y + n))
			ans += map[i].d;
	return ans;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &r);
		init();
		for (int i = 0; i < r; i++)
		{
			scanf("%d%d%d", &map[i].x, &map[i].y, &map[i].d);
		}
		printf("%d\n", (n + m) * 10000 - kruskal());
	}
	return 0;
}