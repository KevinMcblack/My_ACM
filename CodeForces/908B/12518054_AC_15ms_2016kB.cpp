#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
typedef long long ll;
#define mod 1000000007
#define N 5005
using namespace std;
char a[55][55];
int dir[4] = { 0,1,2,3 };
int n, m;
int sx, sy, ex, ey;
char s[120];
int move()
{
	int x = sx, y = sy;
	int i, j;
	for (i = 0; i < strlen(s); i++)
	{
		int d = s[i] - '0';
		for (j = 0; j < 4; j++)
		{
			if (d == dir[j])
			{
				if (j == 0)
					x++;
				if (j == 1)
					x--;
				if (j == 2)
					y++;
				if (j == 3)
					y--;
			}
			if (a[x][y] == '#')
				return 0;
			if (x > n || y > m || x < 1 || y < 1)
				return 0;
			if (a[x][y] == 'E')
				return 1;
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i,j;
		getchar();
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
				{
					scanf("%c", &a[i][j]);
					if (a[i][j] == 'S')
					{
						sx = i;
						sy = j;
					}
					if (a[i][j] == 'E')
					{
						ex = i;
						ey = j;
					}
				}
			getchar();
		}
		scanf("%s", s);
		int sum = 0;
		do {
			sum += move();
		}while(next_permutation(dir, dir + 4));
		printf("%d\n", sum);
	}
    return 0;
}