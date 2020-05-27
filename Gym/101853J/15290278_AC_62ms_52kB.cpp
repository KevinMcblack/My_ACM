#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f3f
const int maxn = 1e4 + 5;
int main()
{
	int t;
	int a[maxn];
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int maxx = 1;
		int p = 0;
		int i = 1;
		for (;;)
		{
			while (abs(a[i] - a[p]) <= 1&&i<n)
			{
				i++;
			}
			if (p == n-1)
				break;
			maxx = max(maxx, i-p);
			p++;
		}
		printf("%d\n", maxx);
	}
	return 0;
}