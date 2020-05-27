#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
char a[1005][1005];
int n, m;
int sx_g, sy_g;
int sx_c, sy_c;
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
char girl[4] = { 'g','i','r','l' };
char cat[3] = { 'c','a','t' };
int p;
int k;
void dfs(int x,int y,int bit)
{
	int dx=x, dy=y;
	if (a[dx][dy] != girl[bit])
		return;
	if (bit ==3)
	{
		p++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		dx = x + dir[i][0], dy = y + dir[i][1];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m)
		{
			dfs(dx, dy, bit + 1);
		}
	}
}
void dfs1(int x, int y, int bit)
{
	int dx = x, dy = y;
	if (a[dx][dy] != cat[bit])
		return;
	if (bit == 2)
	{
		k++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		dx = x + dir[i][0], dy = y + dir[i][1];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m)
		{
			dfs1(dx, dy, bit + 1);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j];
				/*if (a[i][j] == 'g')
					sx_g = i, sy_g = j;
				if (a[i][j] == 'c')
					sx_c = i, sy_c = j;*/
			}
		}
		p = 0;
		k = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 'g')
					dfs(i, j,0);
				if (a[i][j] == 'c')
					dfs1(i, j,0);
			}
		}
		cout << p <<" "<<k<< endl;
	}
	return 0;
}