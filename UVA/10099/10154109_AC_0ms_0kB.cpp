#include <iostream>  
#include <cmath>  
#define max(a, b) ((a) > (b) ? (a) : (b))  
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;
int n, m, q, mmap[110][110];
//弗洛伊德算法 利用动态规划的思想寻找给定的加权图中多源点之间最短路径的算法
//优点：容易理解，可以算出任意两个节点之间的最短距离，代码编写简单。
//缺点：时间复杂度比较高，不适合计算大量数据。
//如果经过下标为k顶点路径比原来两点间路径更短  
//将当前两点间权值设置为更小的一个  
void floyd() {
	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				mmap[i][j] = max(mmap[i][j], min(mmap[i][k], mmap[k][j]));
}
int main() {
	int i, j, u, v, w, k = 1;
	while (~scanf("%d%d", &n, &m)&&n||m) {
		for (i = 0; i<n; i++)		//数组初始化
			for (j = 0; j<n; j++)
				mmap[i][j] = 0;
		for (i = 0; i<m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			mmap[u - 1][v - 1]  = mmap[v - 1][u - 1]  =w; 
		}
		floyd();
		scanf("%d%d%d", &u, &v, &w);
	/*	for (int i = 0; i < n; i++)
		{ 
			for (int j = 0; j < n; j++)
				printf("%d   ", mmap[i][j]);
			printf("\n");
		}*/
		int ans = 0, num = mmap[u - 1][v - 1] - 1;
		/*printf("num %d\n", num);*/
		ans = ceil((double)w / num);//向上取整
		printf("Scenario #%d\n", k++);
		printf("Minimum Number of Trips = %d\n\n", ans);
	}
	return 0;
}