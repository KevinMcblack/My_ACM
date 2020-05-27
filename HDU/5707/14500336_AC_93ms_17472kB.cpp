#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int N = 2005;
char a[N], b[N], c[N];
int dp[N][N];
int main()
{
	int i, j, n, m, k;
	while (~scanf("%s", a + 1))
	{
		memset(dp, 0, sizeof(dp));
		scanf("%s", b + 1);
		scanf("%s", c + 1);
		n = strlen(a + 1);
		m = strlen(b + 1);
		k = strlen(c + 1);
		if (n + m != k)
		{
			puts("No");
			continue;
		}
		dp[0][0] = 1;
		for (i = 0; i <= n; i++)
			for (j = 0; j <= m; j++)
			{
				if (i>0 && c[i + j] == a[i])
					dp[i][j] |= dp[i - 1][j];
				if (j>0 && c[i + j] == b[j])
					dp[i][j] |= dp[i][j - 1];
			}
		if (dp[n][m])
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}