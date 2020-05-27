#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;

int ticket[10], mp[31][31];
double dp[1 << 9][31];
int n, m, p, a, b;

void read(int &x) {
	char ch = getchar(); x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

void sovle()
{
	dp[(1<<n) - 1][a] = 0;//车票都在，人在起点，花费为0
	double res = INF;
	for (int i = (1 << n) - 1; i >= 0; i--){			//选出一种车票剩余状态
		res = min(res,dp[i][b]);							//更新答案
		for (int j = 1; j <= m; j++){				 //枚举起点 
			if (dp[i][j]!=INF) {
				for (int k = 0; k < n; k++) {		 //选择一张剩余车票
					if (i >> k & 1) {					//这张票还没用的话就用掉
						for (int l = 1; l <= m; l++) {//枚举终点 
							if (mp[j][l]) {				  //两点是否联通
								dp[i&~(1 << k)][l] = min(dp[i&~(1 << k)][l],dp[i][j]+(double)mp[j][l]/ticket[k]); //设置第k位为0 找到一个临近点 更新最小值
							}
						}
					}
				}
			}
		}
	}
	if (res == INF) {
		printf("Impossible\n");
	}
	else {
		printf("%.3lf\n", res);
	}
}

int main(int argc, char *argv[])
{
	while (~scanf("%d%d%d%d%d", &n, &m, &p, &a, &b))
	{
		if ((n + m + p + a + b) == 0)
			break;
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < 1 << n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = INF;
			}
		}
		for (int i = 0; i < n; i++) {
			read(ticket[i]);
		}
		int x, y, d;
		for (int i = 0; i < p; i++){
			read(x), read(y), read(d);
			mp[x][y] = mp[y][x] = d;
		}
		sovle();
	}
	return 0;
}