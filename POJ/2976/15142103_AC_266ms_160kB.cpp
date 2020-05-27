#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 0x3f3f3f3f3f
#define eps 1e-6
typedef long long LL;
using namespace std;
const int maxn = 1e3 + 10;
struct MyStruct
{
	double a, b;
}node[maxn];
double t[maxn];
int n,m;
int vjudge(double x)
{
	for (int i = 0; i < n; i++)
		t[i] = node[i].a - x * node[i].b;
	sort(t, t + n);
	double sum = 0;
	for (int i = m; i < n; i++)
		sum += t[i];
	return sum>=0;
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		if (n == 0 && m == 0)   
			break;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &node[i].a);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &node[i].b);
		}
		double l = 0.0, r = 1.0;
		for(int i=0;i<100;i++)
		{
			double mid = (l + r) / 2;
			if (vjudge(mid))
				l = mid;
			else
				r = mid;
		}
		printf("%1.lf\n", l * 100);
	}
	return 0;
}