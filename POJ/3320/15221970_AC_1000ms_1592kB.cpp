#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;
const int maxn = 1e6 + 5;
#define INF 0x3f3f3f3f
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	set<int> s;
	map<int, int> m;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}

	int len = s.size();
	int l = 0, num = 0, t = 0;
	int res = n;

	for (;;)
	{
		while (num < len&&t < n)
		{
			if (m[a[t++]]++ == 0)
				num++;
		}
		if (num < len)
			break;
		res = min(res, t - l);
		if (--m[a[l++]] == 0)
			num--;
	}

	cout << res << endl;
	return 0;
}