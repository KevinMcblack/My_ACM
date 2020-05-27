#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f3f3f
#define maxn 10010
int prime[maxn];
struct MyStruct
{
	int x, step;
};
void init()
{
	int i, j;
	memset(prime,0,sizeof(prime));
	prime[1] = 1;
	for (i = 2; i < maxn; i++)
	{
		if (prime[i] == 0)
			for (j = 2; j*i < maxn; j++)
				prime[j*i] = 1;
	}
}
int bfs(int a,int b)
{
	int vis[maxn];
	int num;
	memset(vis, 0, sizeof(vis));
	queue<MyStruct>Q;
	MyStruct q, p;
	p.x = a;
	p.step = 0;
	vis[a] = 1;
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.front();
		Q.pop();
		if (p.x == b)
			return p.step;
		int t[5];
		t[1] = p.x / 1000;
		t[2] = p.x / 100 % 10;
		t[3] = p.x / 10 % 10;
		t[4] = p.x % 10;
		for (int i = 1; i <= 4; i++)
		{
			int temp = t[i];
			for (int j = 0; j <= 9; j++)
			{
				if (t[i] != j)
				{
					t[i] = j;
					num = t[1] * 1000 + t[2] * 100 + t[3] * 10 + t[4];
				}
				if (num >= 1000 && num <= 9999 && !vis[num] && !prime[num])
				{
					vis[num] = 1;
					q.x = num;
					q.step = p.step + 1;
					Q.push(q);
				}
			}
			t[i] = temp;
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		int ans = bfs(a,b);
		if (ans == -1)
			cout << "Impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}