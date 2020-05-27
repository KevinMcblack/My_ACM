#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
#define INF 0x3f3f3f3f3f3f
const int maxn = 1e3 + 10;

int f[maxn];
vector<P> p;
vector<int> q;
int n;
int find(int x)
{
	return f[x] == x ? f[x] : f[x] = find(f[x]);
}
void unite(int x,int y)
{
	f[find(x)] = find(y);
}
void init()
{
	for (int i = 1; i <= n; i++)
		f[i] = i;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	init();
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b))
			p.push_back(make_pair(a,b));
		else
			unite(a, b);
	}
	for (int i = 1; i <= n; i++)
		if (find(i) == i)
			q.push_back(i);
	cout << q.size() - 1 << endl;
	for (int i = 1; i < q.size(); i++)
		cout << p[i - 1].first << " " << p[i - 1].second << " " << q[i - 1] << " " << q[i] << endl;
	return 0;
}