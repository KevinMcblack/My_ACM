#include <algorithm>
#include <queue>
#include <functional>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
int n, q;
int main()
{
	cin >> n >> q;
	map<int, int>a;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 0; i < q; i++)
	{
		int b;
		cin >> b;
		int ans = 0;
		for (int i = 1 << 30; i >= 1; i /= 2)
		{
			int k = min(a[i], b / i);
			ans += k;
			b -= k * i;
		}
		if (b == 0)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}