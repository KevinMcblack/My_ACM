#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int dir[4][2] = { {1,0}, {-1,0} ,{0,1} ,{0,-1} };
int map[305][305];
int mark[310][310];
struct node {
	int x, y, step;
}temp,a;
bool operator<(const node &a, const node &b)
{
	return a.step > b.step;
}
void bfs()
{
	memset(mark,0,sizeof(mark));
	priority_queue<node> q;
	a.x = 0, a.y = 0, a.step = 0, mark[0][0] = 1;
	q.push(a);
	while (!q.empty())
	{
		a = q.top();
		q.pop();
		if (map[a.x][a.y] == -1)
		{
			cout << a.step << endl;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			temp.x = a.x + dir[i][0];
			temp.y = a.y + dir[i][1];
			temp.step = a.step + 1;
			//判断确定安全的或者是暂时安全的
			if (temp.x >= 0 && temp.y >= 0 && (map[temp.x][temp.y] == -1 || map[temp.x][temp.y] > temp.step))
			{
				if (!mark[temp.x][temp.y])
					q.push(temp);
				mark[temp.x][temp.y] = 1;
			}
		}
	}
	cout << -1 << endl;
}
int main()
{
	int n,x,y,step;
	cin >> n;
	memset(map,-1,sizeof(map));
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> step;
		if (map[x][y] == -1)
			map[x][y] = step;
		else
			map[x][y] = min(map[x][y],step);
		for (int j = 0; j < 4; j++)
		{
			int nx = x + dir[j][0];
			int ny = y + dir[j][1];
			if(nx>=0&&ny>=0)
				if (map[nx][ny] == -1)
					map[nx][ny] = step;
				else
					map[nx][ny] = min(map[nx][ny], step);
		}
	}
	bfs();
	return 0;
}