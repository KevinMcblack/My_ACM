#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f3f3f
const int maxn = 1e6 + 10;
int a[maxn], cnt[maxn];
void H_semi_primes()
{
	memset(a,0,sizeof(a));
	memset(cnt, 0, sizeof(cnt));
	for (int i = 5; i < maxn; i += 4)
	{
		for (int j = 5; i*j < maxn; j += 4)
		{
			if (a[i] == 0 && a[j] == 0)
				a[i*j] = 1;
			else
				a[i*j] = -1;
		}
	}
	int k = 0;
	for (int i = 1; i < maxn; i++)
	{
		if (a[i] == 1)
			k++;
		cnt[i] = k;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	H_semi_primes();
	int n;
	while (cin >> n&&n)
	{
		cout << n << " " << cnt[n] << endl;
	}
	return 0;
}