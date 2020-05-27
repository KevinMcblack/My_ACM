#include<stdio.h>
#include<string.h>
int dp[101][101];      //dp[i][j] 表示消耗i的忍耐度和杀j个怪物得到的最大经验值
struct node
{
	int e;     //经验值
	int r;     //忍耐度
}a[101];

int main()
{
	int n, m, k, s, i, j, t;
	while (scanf("%d%d%d%d", &n, &m, &k, &s) != EOF)
	{
		for (i = 1; i <= k; ++i)
			scanf("%d%d", &a[i].e, &a[i].r);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= k; ++i)   //k表示怪物种类---对不同怪物遍历一遍
			for (j = a[i].r; j <= m; ++j)  //m表示保留的忍耐度
				for (t = 1; t <= s; ++t)    // s表示杀的怪物数
					if (dp[j][t]<dp[j - a[i].r][t - 1] + a[i].e)
						dp[j][t] = dp[j - a[i].r][t - 1] + a[i].e;
		if (dp[m][s] >= n)     //表示能过升级
		{
			for (i = 0; i <= m; ++i)   //寻找能够升级所消耗的最小忍耐度,只用找消耗相同忍耐度的情况下，令杀怪数量最多，
				if (dp[i][s] >= n) //那么d[i][s]一定是消耗i忍耐度的情况下，获得的最大经验值
				{
					printf("%d\n", m - i);
					break;
				}
		}
		else
			printf("-1\n");
	}
	return 0;
}