#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100117;
int n, query;
int num[MAXN];

int F_Min[MAXN][20], F_Max[MAXN][20];

void Init()
{
	for (int i = 1; i <= n; i++)
	{
		F_Min[i][0] = F_Max[i][0] = num[i];
	}

	for (int i = 1; (1 << i) <= n; i++)  //按区间长度递增顺序递推
	{
		for (int j = 1; j + (1 << i) - 1 <= n; j++)  //区间起点
		{
			F_Max[j][i] = max(F_Max[j][i - 1], F_Max[j + (1 << (i - 1))][i - 1]);
			F_Min[j][i] = min(F_Min[j][i - 1], F_Min[j + (1 << (i - 1))][i - 1]);
		}
	}
}

int Query_max(int l, int r)
{
	int k = (int)(log(double(r - l + 1)) / log((double)2));
	return max(F_Max[l][k], F_Max[r - (1 << k) + 1][k]);
}

int Query_min(int l, int r)
{
	int k = (int)(log(double(r - l + 1)) / log((double)2));
	return min(F_Min[l][k], F_Min[r - (1 << k) + 1][k]);
}

int main()
{
	int a, b;
	scanf("%d %d", &n, &query);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);
	Init();
	while (query--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", Query_max(a, b) - Query_min(a, b));
	}
	return 0;
}
