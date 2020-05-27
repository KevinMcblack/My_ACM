#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
const int maxn = 3e2+ 5;
const int maxv = 2e4 + 7;
const int maxe = 2e6 + 7;
#define INF 0x3f3f3f3f
typedef pair<int, int> P;
int n, m;
int dis[maxn][maxn];
int a[maxn];

void floyd()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				dis[j][k] = min(dis[j][k],dis[j][i]+dis[i][k]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	fill(dis[0],dis[0]+maxn*maxn,INF);
	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		for (int j = 0; j < t; j++)
			cin >> a[j];
		for (int j = 0; j < t; j++)
			for (int k = 0; k < j; k++)
				dis[a[j]][a[k]] = dis[a[k]][a[j]] = 1;
	}
	floyd();
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
			if (i != j)
				sum += dis[i][j];
		ans = min(ans, sum);
	}
	cout << 100 * ans / (n-1) << endl;
	return 0;
}