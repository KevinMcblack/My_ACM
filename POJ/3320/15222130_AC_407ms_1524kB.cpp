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
	set<int> s;
	map<int, int> m;
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
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

	printf("%d\n", res);
	return 0;
}