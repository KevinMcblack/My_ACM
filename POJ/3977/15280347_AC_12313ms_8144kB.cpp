#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f3f
const int maxn = 45;

LL a[maxn];
int n;

LL ABS(LL x)
{
	return x < 0 ? -x : x;
}

int main()
{
	while (~scanf("%d",&n)&&n)
	{
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			if (a[i] == 0)
				k = 1;
		}
		if (k == 1)
		{
			printf("0 1\n");
			continue;
		}
		if (n == 1)
		{
			printf("%lld 1\n", ABS(a[0]));
			continue;
		}

		map<LL, int>m;
		map<LL, int>::iterator it;
		pair<LL, int>ans(ABS(a[0]), 1);
		LL sum = 0;
		int cnt = 0;
		for (int i = 1; i < 1 << (n / 2); i++)
		{
			sum = 0;
			cnt = 0;
			for(int j=0;j<(n/2);j++)
				if ((i >> j) & 1)
				{
					sum += a[j];
					cnt++;
				}
			ans = min(ans, make_pair(ABS(sum), cnt));
			if (m[sum])
				m[sum] = min(m[sum], cnt);
			else
				m[sum] = cnt;
		}
		for (int i = 1; i < 1 << (n - n / 2); i++)
		{
			sum = 0;
			cnt = 0;
			for (int j = 0; j < (n - n / 2); j++)
			{
				if ((i >> j) & 1)
				{
					sum += a[j + n / 2];
					cnt++;
				}
			}
			ans = min(ans,make_pair(ABS(sum),cnt));
			
			it = m.lower_bound(-sum);
			if (it != m.end())
				ans = min(ans, make_pair(ABS(sum+it->first), cnt + it->second));
			if (it != m.begin())
			{
				it--;
				ans = min(ans, make_pair(ABS(sum + it->first), cnt + it->second));
			}
		}
		printf("%lld %d\n", ans.first, ans.second);
	}
	return 0;
}
