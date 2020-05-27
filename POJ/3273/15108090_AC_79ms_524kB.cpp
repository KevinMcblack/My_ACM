#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int n, m;
int maxx = -1;
int vjudge(int x)
{
	int cnt = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (sum > x)
		{
			sum = a[i];
			cnt++;
		}
	}
	if (cnt < m)
		return 1;
	else
		return 0;
}
int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);*/
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
	}
	/*sort(a, a + n);*/
	int l = maxx, r = INF;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (vjudge(mid))
			r = mid;
		else
			l = mid+1;
	}
	printf("%d\n", l);
	return 0;
}
