#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;
const int maxn = 1000500;
int vis[maxn];
int main()
{
	int n;
	int k;
	while (~scanf("%d", &n))
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &k);
			vis[k]++;
		}
		for (int i = 0; i < maxn; i++)
		{
			vis[i + 1] += vis[i] /2;
			vis[i] %= 2;
		}
		long long ans = 0;
		for (int i = 0; i < maxn; i++)
		{
			ans += vis[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}