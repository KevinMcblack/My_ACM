#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f3f3f
const int maxn = 1e4 + 10;
double a[maxn];
int n, m;
int vjude(double x)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] / x;
	return sum >= m;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	while (~scanf("%d%d",&n,&m))
	{
		for (int i = 0; i < n; i++)
			scanf("%lf", &a[i]);
		double l = 0, r = INF;
		for (int i = 0; i < 100; i++)
		{
			double mid = (l + r) / 2;
			if (vjude(mid))
				l = mid;
			else
				r = mid;
		}
		printf("%.2lf\n", floor(r*100)/100);
	}
	return 0;
}