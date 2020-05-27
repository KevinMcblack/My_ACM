#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;
const int mod = 1e6;
const int inf = 0x3f3f3f3f;
int main()
{
	int n; 
	int dp[150][3];
	int m;
	while (cin >> n)
	{
		memset(dp,inf,sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> m;
			dp[i][0] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i-1][0]) + 1;
			if (m == 1)
				dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
			else if (m == 2)
				dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
			else if (m == 3)
			{
				dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
				dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
			}
		}
		cout << min(min(dp[n][1], dp[n][2]), dp[n][0]) << endl;
	}
	return 0;
}
