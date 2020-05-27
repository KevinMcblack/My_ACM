#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
typedef pair<int, int> P;
const int maxn = 1e5 + 5;
set<P>s;
set<P>::iterator it;
int gcd(int a,int b)
{
	if (b == 0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (m < n - 1)
		{
			cout << "Impossible" << endl;
			continue;
		}
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (gcd(i, j) == 1)
				{
					ans++;
					s.insert(make_pair(i, j));
				}
				if (ans == m)
					break;
			}
			if (ans == m)
				break;
		}
		if (ans < m)
			cout << "Impossible" << endl;
		else
		{
			cout << "Possible" << endl;
			for (it = s.begin(); it != s.end(); it++)
			{
				cout << it->first << " " << it->second << endl;
			}
		}
	}
	return 0;
}