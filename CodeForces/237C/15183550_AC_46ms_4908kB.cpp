#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f3f
#define eps 1e-6
typedef long long LL;
using namespace std;
const int maxn = 1e6+5;
bool prime[maxn];
int cnt[maxn];
void getPrime()
{
	memset(prime,true,sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i <= maxn; i++)
	{
		if (prime[i])
			for (int j = 2 * i; j < maxn; j += i)
				prime[j] = false;
	}
}
void init()
{
	cnt[0] = 0;
	for (int i = 1; i <= maxn; i++)
	{
		if (prime[i])
			cnt[i] = cnt[i - 1] + 1;
		else
			cnt[i] = cnt[i - 1];
	}
}
int a, b, k;

int vjudge(int mid)
{
	for (int i = a; i <= b - mid + 1; i++)
	{
		if (cnt[i + mid - 1] - cnt[i - 1] >= k)
			continue;
		else
			return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	getPrime();
	init();
	while (cin >> a >> b >> k)
	{
		int r = b - a + 1;
		int flag = 0;
		int l = 1;
		if (vjudge(r))
		{
			cout << -1 << endl;
			continue;
		}
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (vjudge(mid))
				l = mid + 1;
			else
				r = mid - 1;
		}
		cout << l << endl;
	}
	return 0;
}