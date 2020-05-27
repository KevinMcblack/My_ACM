#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f3f
const int maxn = 1e5 + 5;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		LL a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (c*c % 2 == 0)
			printf("%lld\n", c*c / 2);
		else
		{
			double k = (double)c * c / 2;
			printf("%.6lf\n", k);
		}
	}
	return 0;
}