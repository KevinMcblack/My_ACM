#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int map[5][5];
int a[1000000];
int countif;
int length;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void dfs(int x,int y,int bit,int sum)
{
	if (bit == 6)
	{
		a[length++] = sum;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int dx = x + dir[i][0], dy = y + dir[i][1];
		if (dx >= 0 && dx < 5 && dy >= 0 && dy < 5)
			dfs(dx,dy,bit+1,sum*10+map[dx][dy]);
	}
}
int main()
{
	memset(a,0,sizeof(a));
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> map[i][j];
	countif = 0;
	length = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
				dfs(i,j,0,0);
	sort(a, a + length);
	for (int i = 0; i < length; i++)
		if (a[i] != a[i + 1])
			countif++;
	cout << countif << endl;
	return 0;
}