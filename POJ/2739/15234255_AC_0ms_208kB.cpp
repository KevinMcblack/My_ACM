#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
typedef long long LL;
using namespace std;
const int maxn = 1e4+5;
int n;
int is[maxn];
int prime[maxn];
int p = 0;
void getPrime()
{
	memset(is, 1, sizeof(is));
	for (int i = 2; i <= maxn; i++)
		if (is[i])
			for (int j = i * 2;j<maxn; j += i)
			{
				is[j] = 0;
			}
	for (int i = 2; i <= maxn; i++)
		if (is[i])
			prime[p++] = i;
}
int main()
{
	getPrime();
	while (~scanf("%d", &n) && n)
	{
		int s = 0, t = 0, sum = 0;
		int res = 0;
		for (;;)
		{
			while (t < p&&sum < n)
				sum += prime[t++];
			if (sum < n)
				break;
			else if(sum>n)
				sum -= prime[s++];
			else
			{
				res++;
				sum -= prime[s++];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
