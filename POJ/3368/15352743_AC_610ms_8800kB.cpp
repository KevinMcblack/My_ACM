#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 100017;
int num[maxn], f[maxn], MAX[maxn][20];
int n;

int rmq_max(int l, int r)
{
	if (l > r)
		return 0;
	int k = log((double)(r - l + 1)) / log(2.0);
	return max(MAX[l][k], MAX[r - (1 << k) + 1][k]);
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		MAX[i][0] = f[i];
	}
	int k = log((double)(n + 1)) / log(2.0);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j + (1 << i) - 1 <= n; j++)
		{
			MAX[j][i] = max(MAX[j][i - 1], MAX[j + (1 << (i - 1))][i - 1]);
		}
	}
}

int main()
{
	int a, b, q;
	while (scanf("%d", &n) && n)
	{
		scanf("%d", &q);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
		}
		//sort(num + 1, num + n + 1);
		f[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			if (num[i] == num[i - 1])
			{
				f[i] = f[i - 1] + 1;
			}
			else
			{
				f[i] = 1;
			}
		}

		init();

		for (int i = 1; i <= q; i++)
		{
			scanf("%d%d", &a, &b);
			int t = a;
			while (t <= b && num[t] == num[t - 1])
			{
				t++;
			}
			int cnt = rmq_max(t, b);
			int ans = max(t - a, cnt);
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*
10 3
-1 -1 1 2 1 1 1 10 10 10
2 3
1 10
5 10
*/
