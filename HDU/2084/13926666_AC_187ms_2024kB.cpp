#include <iostream>
#include<cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <assert.h>
using namespace std;
static int xx = []() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[105][105];
		int dp[105][105] = {0};
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
			{
				cin >> a[i][j];
				dp[i][j] = a[i][j];
			}
		for (int i = n-1; i >=0; i--)
		{
			for (int j = 0; j <=i; j++)
			{
				dp[i][j] = max(dp[i + 1][j + 1], dp[i + 1][j]);
				dp[i][j] += a[i][j];
			}
		}
		cout << dp[0][0] << endl;
	}
	return 0;
}