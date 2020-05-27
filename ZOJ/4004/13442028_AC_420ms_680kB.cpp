#include <iostream>  
#include <cmath>  
#include <string>
#include <cstdio>  
#include <algorithm>
#include <map>
using namespace std;

int a[100005];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (m == 0)
		{
			printf("0\n");
			continue;
		}
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		long long sum = 0;
		for (int i = 0; i < m; i++)
		{
			sum += a[i] * a[2*m - 1 - i];
		}
		cout << sum << endl;
	}
	return 0;
}