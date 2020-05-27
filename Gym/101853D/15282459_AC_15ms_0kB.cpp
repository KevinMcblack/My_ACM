#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f3f
const int maxn = 100;
int a[maxn];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] != 0)
				k++;
		}
		printf("%d\n", k);
	}
	return 0;
}
