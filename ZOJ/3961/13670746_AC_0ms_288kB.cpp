#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
#include <math.h>
using namespace std;
struct time
{
	int l, r;
};
int main()
{
	int t;
	struct time a[150];
	struct time b[150];
	int n, m,x,y;
	scanf("%d", &t);
	while (t--)
	{
		int count = 0;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		for (int i = 0; i < x; i++)
			scanf("%d%d", &a[i].l, &a[i].r);
		for (int i = 0; i < y; i++)
			scanf("%d%d", &b[i].l, &b[i].r);
		for (int i = 0; i < x; i++)
		{
			if (a[i].r - a[i].l + 1 < m)
				continue;
			for (int j = 0; j < y; j++)
			{
				if (b[j].r - b[j].l + 1 < m)
					continue;
				int left = max(a[i].l, b[j].l);
				int right = min(a[i].r, b[j].r);
				int len = right - left+1;
				if (len >= m)
					count += (len-m+1);
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
