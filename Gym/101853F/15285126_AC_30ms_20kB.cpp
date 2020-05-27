#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f3f
const int maxn = 150;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int h1, m1, h2, m2;
		LL sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
			sum += ((h2 * 60 + m2) - (h1 * 60 + m1));
		}
		sum /= 60;
		if (sum >= m)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
