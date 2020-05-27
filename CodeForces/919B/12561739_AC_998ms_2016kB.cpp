#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
#include <math.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		ll i;
		ll k;
		int sum = 0;
		int ans = 0;
		for (i = 0; ; i++)
		{
			k = i;
			sum = 0;
			while (k)
			{
				sum += (k % 10);
				k /= 10;
			}
			if (sum == 10)
				ans++;
			if (ans == n)
			{
				printf("%lld\n", i);
				break;
			}
		}
	}
	return 0;
}
