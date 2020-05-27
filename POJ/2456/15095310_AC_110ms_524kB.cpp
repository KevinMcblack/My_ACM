#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int n, m;
int vjudge(int x)
{
	int last = 0;
	for (int i = 1; i < m; i++)
	{
		int cnt= last + 1;
		while (cnt < n&&a[cnt]-a[last]<x)
			cnt++;
		if (cnt == n)
			return 0;
		last = cnt;
	}
	return 1;
}
int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);*/
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 0, r = INF;
	while (l < r-1)
	{
		int mid = (l + r) / 2;
		if (vjudge(mid))
			l = mid;
		else
			r = mid;
	}
	printf("%d\n", l);
	return 0;
}
