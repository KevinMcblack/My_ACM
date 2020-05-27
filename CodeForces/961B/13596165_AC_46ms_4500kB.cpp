#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	int n, k;
	while (~scanf("%d%d", &n, &k))
	{
		int a[100000], b[100000], sum=0, i,s=0,m=-1;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
			if (b[i])
				sum += a[i];
		}
		for (i = 0; i < n; i++)
		{
			if (!b[i])
				s += a[i];
			if (i - k >= 0 && !b[i - k])
				s -= a[i-k];
			m = max(m, s);
		}
		printf("%d\n", m + sum);
	}
	return 0;
}
