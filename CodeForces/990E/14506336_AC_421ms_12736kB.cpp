#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#define ll long long
#define inf 1e18
using namespace std;
const int maxn = 1e6 + 7;
int n, m, k, s[maxn];
bool vis[maxn];
ll a[maxn];
int main()
{
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		memset(s, 0, sizeof(s));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);
			vis[x] = 1;
		}
		for (int i = 1; i <= k; i++)
			scanf("%lld", &a[i]);
		if (vis[0])
		{
			printf("-1\n");
			continue;
		}
		int len = 0;
		ll ans = inf;
		for (int i = 0; i <= n; i++)
		{
			if (vis[i])
				s[i] = s[i - 1] + 1;
			else
				s[i] = 0;
			len = max(len, s[i]);
		}
		for (int i = len + 1; i <= k; i++)
		{
			ll cnt = 0;
			for (int j = 0; j < n; j += i)
			{
				if (vis[j])
					j -= s[j];
				cnt++;
			}
			ans = min(ans, cnt*a[i]);
		}
		if (ans >= inf)
			printf("-1\n");
		else
			printf("%lld\n", ans);
	}
	return 0;
}