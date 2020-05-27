#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f3f
using namespace std;
const int maxn = 5e4 + 10;
int a[maxn];
int n, m,k;
int vjudge(int x)
{
	int last = 0;
	int cnt = 0;
	for (int i = 1; i <= n+1;i++)
	{
		if (a[i] - a[last] >= x)
			last = i;
		else
			cnt++;
	}
	if (cnt <= k)
		return 1;
	else
		return 0;
}
int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);*/
	scanf("%d%d%d", &m, &n,&k);
	int i;
	a[0] = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	a[i] = m;
	sort(a, a + n+1);
	int l = 0, r = INF;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (vjudge(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d\n", r);
	return 0;
}