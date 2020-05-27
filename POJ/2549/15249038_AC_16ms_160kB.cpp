#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
typedef long long LL;
using namespace std;
const int maxn = 1e3+5;
int a[maxn];
int n;
void sovle()
{
	for (int d = n - 1; d >= 0; d--)
	{
		for (int c = n - 1; c >= 0; c--)
		{
			if (d == c)
				continue;
			int temp = a[d] - a[c];
			int l = 0, r = c - 1;
			while (l < r)
			{
				if (a[l] + a[r] == temp)
				{
					printf("%d\n", a[d]);
					return;
				}
				else if (a[l] + a[r] < temp)
					l++;
				else
					r--;
			}
		}
	}
	printf("no solution\n");
}
int main()
{
	while (~scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		sovle();
	}
	return 0;
}
