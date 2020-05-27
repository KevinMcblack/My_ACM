#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3f3f
typedef long long LL;
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int n,k;
int vjudge(LL x)
{
	LL sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x)
			sum += ceil((a[i] - x)*1.0 / (k - 1));
	}
	if (sum > x)
		return 1;
	else
		return 0;
}
int main()
{
	int maxx = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		maxx = max(maxx,a[i]);
	}
	scanf("%d", &k);
	if (k == 1)
	{
		printf("%d\n", maxx);
		return 0;
	}
	LL l = 0, r = maxx;
	while (l <= r)
	{
		LL mid = (l + r) / 2;
		if (vjudge(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}