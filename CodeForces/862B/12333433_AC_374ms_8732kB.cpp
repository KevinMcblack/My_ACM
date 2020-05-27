#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> vec[100100];
int vis[100100];
ll a1, a2;
int n;
void dfs(int x, int step)
{
	for (int i = 0; i < vec[x].size(); i++)
	{
		if (!vis[vec[x][i]])
		{
			vis[vec[x][i]] = 1;
			if (step & 1)
				a1++;
			else
				a2++;
			dfs(vec[x][i], step + 1);
		}
	}
}
int main()
{
	int a, b;
	a1 = 1;
	a2 = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	vis[1] = 1;
	dfs(1, 0);
	cout << a1*a2 - (n - 1) << endl;
	return 0;
}
