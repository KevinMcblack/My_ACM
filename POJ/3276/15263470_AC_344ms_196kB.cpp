#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f3f
const int maxn = 5010;
int a[maxn];
int n, f[maxn];
int sovle(int k)
{
	memset(f,0,sizeof(f));
	int ans = 0;
	int sum = 0;
	for (int i = 0; i + k <= n; i++)
	{
		if ((a[i] + sum) & 1)
		{
			ans++;
			f[i] = 1;
		}
		sum += f[i];
		if (i - k + 1 >= 0)
			sum -= f[i - k + 1];
	}
	for (int i = n - k + 1; i < n; i++)
	{
		if ((a[i] + sum) & 1)
			return -1;
		if (i - k + 1 >= 0)
			sum -= f[i - k + 1];
	}
	return ans;
}
int main()
{
	char s[2];
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s",s);
			if (s[0] == 'F')
				a[i] = 0;
			else
				a[i] = 1;
		}
		int K = 1, M = n;
		for (int k = 1; k <= n; k++)
		{
			int m = sovle(k);
			if (m >= 0 && M > m)
			{
				M = m;
				K = k;
			}
		}
		printf("%d %d\n", K, M);
	}
	return 0;
}
