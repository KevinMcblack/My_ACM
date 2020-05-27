#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3f3f
#define eps 1e-6
typedef long long LL;
using namespace std;
const int maxn = 5e4+10;
struct MyStruct
{
	int x, y;
}a[maxn];
bool cmp(MyStruct a, MyStruct b)
{
	return a.x + a.y > b.x + b.y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		LL sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].x >> a[i].y;
			sum += a[i].x;
		}
		sort(a, a + n, cmp);
		LL ans = -INF;
		for (int i = 0; i < n; i++)
		{
			sum -= a[i].x;
			ans = max(ans, sum - a[i].y);
		}
		cout << ans << endl;
	}
	return 0;
}