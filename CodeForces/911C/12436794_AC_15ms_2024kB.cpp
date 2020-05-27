#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n, m, p;
	while (cin >> n >> m >> p)
	{
		if (n == 1 || m == 1 || p == 1)
		{
			printf("YES\n");
			continue;
		}
		int a[1505] = { 0 };
		a[n]++, a[m]++, a[p]++;
		if(a[2]>=2||a[2]==1&&a[4]>=2)
			printf("YES\n");
		else if(a[3]>=3)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
