#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
const int maxn = 2007;
int map[maxn][maxn], sum[maxn], n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf("%1d", map[i] + j);
			sum[j] += map[i][j];
		}
	for (int i = 1, j; i <= n; i++) {
		for (j = 1; j <= m; j++) 
			if (sum[j] - map[i][j] == 0) 
				break;
		if (j > m) 
			return 0 * puts("YES");
	}
	return 0 * puts("NO");
}