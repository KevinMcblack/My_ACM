#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
typedef long long LL;
using namespace std;
const int maxn = 1e6+5;
LL n;
LL b[maxn][2];
int main()
{
	while (~scanf("%lld",&n))
	{
		LL ans = 0;
		LL sum = 0;
		LL s = 1, t = 1;
		LL r = (int)sqrt(n*1.0);
		while (1)
		{
			while (t <=r&&sum < n)
			{
				sum += t * t;
				t++;
			}	
			if (sum < n)
				break;
		    if(sum==n)
			{
				b[ans][0] = s;
				b[ans][1] = t;
				ans++;
			}
			sum -= s * s;
			s++;
		}
		printf("%lld\n", ans);
		for (LL i = 0; i < ans; i++)
		{
			printf("%lld ", b[i][1] - b[i][0]);
			for (LL j = b[i][0]; j < b[i][1]-1; j++)
				printf("%lld ", j);
			printf("%lld\n", b[i][1]-1);
		}
	}
	return 0;
}
