#include <stdio.h>
#include<algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
struct edge {
	int s;
	int h;
	ll w;
}a[100050];
int vis[100010];
bool cmp(struct edge a, struct edge b)//从小到大排列   
{
	return a.w<b.w;
}
int main()
{
	int n, m, k;
	ll x;
	scanf("%d%d%d", &n,&m,&k);
	int i;
	for (i = 0; i < m; i++)
		scanf("%d%d%lld", &a[i].s, &a[i].h, &a[i].w);
	sort(a, a + m, cmp);
	for (int i = 0; i<k; i++)
	{
		scanf("%lld", &x);
		vis[x] = 1;
	}
	ll ans = 0x3fffffff;
	for (int i = 0; i<m; i++)
	{
		if ((vis[a[i].s] && !vis[a[i].h]) || (!vis[a[i].s] && vis[a[i].h]))
			ans = min(ans, a[i].w);
	}
	if (ans == 0x3fffffff)   //没有可连通的路   
		printf("-1\n");
	else
		printf("%lld\n", ans);
	return 0;
}
