#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int pre[maxn], r[maxn];
int n;
void init()
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] = i;
		r[i] = 0;
	}
}
int find(int x)
{
	if (pre[x] == x)
		return x;
	else
	{
		int t = find(pre[x]);
		r[x] = (r[x] + r[pre[x]]) % 2;
		return pre[x] = t;
	}
}
void unite(int x, int y)
{
	int xx = find(x);
	int yy = find(y);
	pre[xx] = yy;
	if (r[y] == 0)
		r[xx] = 1 - r[x];
	else
		r[xx] = r[x];
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m;
		scanf("%d%d", &n, &m);
		init();
		while (m--)
		{
			char s[5];
			int x, y;
			scanf("%s%d%d", s, &x, &y);
			if (s[0] == 'A')
			{
				if (same(x, y) != 1)
					printf("Not sure yet.\n");
				else if (r[x] == r[y])
				{
					printf("In the same gang.\n");
				}
				else
				{
					printf("In different gangs.\n");
				}
			}
			else
			{
				unite(x, y);
			}
		}
	}
	return 0;
}