#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
typedef long long ll;
#define mod 1000000007
#define N 5005
using namespace std;
ll dp[N][N];
int main()
{
	int n;
	char c;
	while (scanf("%d", &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 1;
		for (int i = 1; i < n; i++)
		{
			cin >> c;
			if (c == 'f')
			{
				for (int j = 0; j <= n; j++)
					dp[i + 1][j + 1] = dp[i][j];
			}
			else
			{
				ll sum = 0;
				for (int j = n ; j >= 0; j--)
				{
					sum += dp[i][j];
					sum %= mod;
					dp[i + 1][j] = sum;
				}
			}
		}
		cin >> c;
		ll ans = 0;
		for (int i = 0; i <= n; i++)
		{
			ans += dp[n][i];
			ans %= mod;
		}
		cout << ans << endl;
	}
    return 0;
}