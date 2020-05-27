#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f3f
const int maxn = 16+1;
int n;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		int k = sqrt(n*1.0 / 6*1.0);
		printf("%d\n", k);
	}
	return 0;
}
