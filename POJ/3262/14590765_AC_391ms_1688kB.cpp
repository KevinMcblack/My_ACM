#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
struct MyStruct
{
	double t, d;
}a[100005];
bool cmp(MyStruct aa, MyStruct bb)
{
	return (aa.d / aa.t) > (bb.d / bb.t);
}
int main()
{
	int n;
	long long tol = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf", &a[i].t, &a[i].d);
		tol += a[i].d;
	}
	sort(a, a + n, cmp);
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		tol -= a[i].d;
		sum += (2 * a[i].t*tol);
	}
	printf("%lld\n",sum);
	return 0;
}