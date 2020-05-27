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
int cnt;
struct node
{
	int x, y, d;
}map[maxn];
bool cmp(node a, node b)
{
	return a.d < b.d;
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
int unite(int a, int b)
{
	int x = find(a);
	int y = find(b);
	if (x != y)
	{
		father[y] = x;
		return 1;
		cnt++;
	}
	return 0;
}
int kruskal()
{
	sort(map, map + r, cmp);
	cnt = 0;
	int maxx = -1;
	for (int i = 0; i < r; i++)
		if (unite(map[i].x, map[i].y))
		{
			maxx =max( maxx,map[i].d);
			cnt++;
			if (cnt == n - 1)
				break;
		}
	return maxx;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r;
	init();
	for (int i = 0; i < r; i++)
	{
		cin >> map[i].x >> map[i].y >> map[i].d;
	}
	cout << kruskal() << endl;
	return 0;
}