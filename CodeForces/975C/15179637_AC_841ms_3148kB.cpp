#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f3f
#define eps 1e-6
typedef long long LL;
using namespace std;
const int maxn = 2e5+10;
int n, q;
LL a[maxn],sum[maxn];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	sum[0] = 0;
	for (LL i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	LL t = 0;
	LL k;
	for (LL i = 1; i <= q; i++)
	{
		cin >> k;
		t += k;
		if (t >= sum[n])
			t = 0;
		LL pos = upper_bound(sum, sum + 1 + n, t) - sum - 1;
		cout << n-pos << endl;
	}
	return 0;
}