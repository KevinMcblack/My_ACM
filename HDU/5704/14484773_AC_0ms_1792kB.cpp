#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int c[200];
	int t, n, i, sum, x;
	cin >> t;
	while (t--)
	{
		sum = 0;
		memset(c, 0, sizeof(c));
		cin >> n;
		for (i = 1; i < n; i++)
		{
			cin>>x;
			c[x]++;
			sum += x;
		}
		x = 2 * sum / (3 * n - 2);
		printf("%d %.2f\n", x, 1.0 / (c[x] + 1));
	}
	return 0;
}