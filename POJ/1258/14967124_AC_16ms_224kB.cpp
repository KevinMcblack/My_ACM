#include <stdio.h>
#include<algorithm>
#include <stdlib.h>
#include <iostream>
using namespace std;
int f[200], ans, n, len;

struct ege
{
	int x, y, d;
}dis[20022];

int find(int x)
{
	if (f[x] == x)
	{
		return x;//父节点
	}
	else
	{
		return f[x] = find(f[x]);
	}
}

int un(int x, int y)

{
	int fx, fy;
	fx = find(x);
	fy = find(y);
	if (fx == fy)
	{
		return 0;
	}
	else
	{
		f[fy] = fx;//WA了好久，没想到问题出在这，并查集都忘了，要更新根节点的父节点
		return 1;
	}
}

bool compare(ege a, ege b)
{
	return a.d<b.d;
}
void krus()
{
	sort(dis, dis + len, compare);
	int i, j, k = 1;
	j = len;
	for (i = 0; i<j; i++)
	{
		if (un(dis[i].x, dis[i].y) == 1)
		{
			ans += dis[i].d;
			k++;
			if (k == n)
			{
				return;
			}
		}
	}
}

int main()
{
	int i, j, k;
	while (scanf("%d", &n) != EOF)
	{
		ans = 0;
		for (i = 1, len = 0; i <= n; i++)
		{
			f[i] = i;
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &k);
				if (i != j)
				{
					dis[len].x = i;
					dis[len].y = j;
					dis[len++].d = k;
				}
			}
		}
		krus();
		printf("%d\n", ans);
	}
	return 0;
}

