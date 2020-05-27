#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define INF 1e7+10
#define eps 1e-6
typedef long long LL;
using namespace std;
const int maxn = 1e5 + 10;
struct MyStruct
{
	double x, y;
}node[maxn];
struct test
{
	double x;
	int mark;
}t[maxn];
bool cmp(test a, test b)
{
	return a.x > b.x;
}
int n,m;
int vjudge(double mid)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		t[i].x = node[i].x - mid * node[i].y;
		t[i].mark = i+1;
	}
	sort(t, t + n,cmp);
	for (int i = 0; i < m; i++)
	{
		sum += t[i].x;
	}
	return sum >= 0;
}
int main()
{
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &node[i].x, &node[i].y);
		}
		double l = 0, r = INF;
		while (r - l>eps)
		{
			double mid = (l + r) / 2;
			if (vjudge(mid))
				l = mid;
			else
				r = mid;
		}
		for (int i = 0; i < m - 1; i++)
			printf("%d ", t[i].mark);
		printf("%d\n", t[m - 1].mark);
	}
	return 0;
}