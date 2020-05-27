#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<vector>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[35];
int main() {
	ll n, m;
	while (scanf("%lld%lld", &n, &m) != EOF)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			if (a[i] > 2 * a[i - 1]&&i!=0)
				a[i] = 2 * a[i - 1];
		}
		ll ans = 0;
		for (i = n; i <= 30 ; i++)
			a[i] = 2 * a[i - 1];
		for (i = 0; i <= 30 ; i++)
		{
			if (ans > a[i])
				ans = a[i];
			if (m&(1 << i))
				ans += a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
