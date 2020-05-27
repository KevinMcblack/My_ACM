#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[100005];
int main() {
	int i;
	int n;
	cin >> n;
	int minv = 0x7fffffff;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		minv = min(a[i], minv);
	}
	int ans = 0x7fffffff;
	int it = -1;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == minv)
		{
			it = i;
			break;
		}
	}
	for (i = it + 1; i <= n; i++)
	{
		if (a[i] == minv)
		{
			ans = min(i - it, ans);
			it = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
