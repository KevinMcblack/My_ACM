#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n, a, b;
	while (scanf("%d%d%d", &n, &a, &b) != EOF)
	{
		int i,j;
		int avea;
		int aveb;
		int maxx = 0;
		if (a + b == n)
			maxx = 1;
		for (i = 1; i < n; i++)
		{
			avea = a / i;
			aveb = b / (n - i);
			maxx = max(maxx, min(avea, aveb));
		}
		printf("%d\n", maxx);
	}
	return 0;
}
