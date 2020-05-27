#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <algorithm>
#define LL  long long
const int mod = 1e9 + 7;
const int  maxn = 2000000 + 10;
using namespace std;
LL dp[maxn];
LL sum[maxn];
int main()
{
	int t, k;
	cin >> t >> k;
	dp[0] = 1;
	sum[0] = 0;
	for (int i = 1; i < k; i++)
	{
		dp[i] = 1;
		sum[i] = sum[i - 1] + dp[i];
	}
	for (int i = k; i <= 100000 + 5; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - k]) % mod;
		sum[i] = sum[i - 1] + dp[i];
		sum[i] %= mod;
	}
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << (sum[b] - sum[a - 1] + mod) % mod << endl;
	}
	return 0;
}
