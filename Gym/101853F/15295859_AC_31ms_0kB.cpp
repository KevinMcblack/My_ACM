#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f3f
const int maxn = 150;
struct MyStruct
{
	int a, b;
}t1[maxn], t2[maxn];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int m, n;
		LL sum1 = 0, sum2 = 0;
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; i++)
		{
			scanf("%d:%d", &t1[i].a, &t1[i].b);
			scanf("%d:%d", &t2[i].a, &t2[i].b);	
			if (t2[i].a > t1[i].a)
			{
				sum2 += (t2[i].b + 60 - t1[i].b);
				sum1 += (t2[i].a - t1[i].a-1);
			}	
			else
				sum2 += (t2[i].b - t1[i].b);
		}
		sum1 *= 60;
		if ((sum1 + sum2) / 60 >= n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}