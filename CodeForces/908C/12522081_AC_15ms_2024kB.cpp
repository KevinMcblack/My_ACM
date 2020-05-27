#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
#include <math.h>
typedef long long ll;
#define mod 1000000007
#define N 5005
using namespace std;
int main()
{
	int n, r;
	int a[1500];
	while (scanf("%d%d", &n, &r) != EOF)
	{
		int i,j;
		double b[1500];
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			double ans = r;
			for (j = 0; j < i; j++)
			{
				int dx = abs(a[j] - a[i]);
				if (dx <= 2 * r)
				{
					ans = max(ans, b[j] + sqrt(4 *r*r - dx*dx));
				}
			}
			b[i] = ans;
		}
		for (i = 0; i < n; i++)
			printf("%.10lf ", b[i]);
		printf("\n");
	}
    return 0;
}
