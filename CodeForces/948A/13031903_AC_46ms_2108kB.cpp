#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
const int N = 500 + 10;
int n, m;
char s[N][N];
bool judge(int x, int y)
{
	if (x >= 0 && x<n&&y >= 0 && y<m)
		return 1;
	return 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++)
		scanf("%s", s[i]);
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			if (s[i][j] == 'S')
				if ((judge(i + 1, j) && s[i + 1][j] == 'W')
					|| (judge(i - 1, j) && s[i - 1][j] == 'W')
					|| (judge(i, j + 1) && s[i][j + 1] == 'W')
					|| (judge(i, j - 1) && s[i][j - 1] == 'W'))
				{
					puts("No");
					return 0;
				}
	puts("Yes");
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
			printf("%c", s[i][j] == '.' ? 'D' : s[i][j]);
		puts("");
	}
	return 0;
}