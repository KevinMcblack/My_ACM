#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	double a[550];
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> a[i];
		sort(a, a + m);
		if (m % 2 == 0)
		{
			printf("%.3lf\n", (a[m / 2 - 1] + a[m/2]) / 2);
		}
		else
			printf("%.3lf\n", a[m/2]);
	}
}