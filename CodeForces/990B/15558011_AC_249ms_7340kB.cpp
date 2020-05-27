#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<int>v;
map<int, int>m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	int t;
	while (cin >> n >> k)
	{
		m.clear();
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> t;
			v.push_back(t);
			m[t]++;
		}
		sort(v.begin(), v.end());
		/*v.erase(unique(v.begin(), v.end()), v.end());
		int len = v.size();*/
		int len = unique(v.begin(), v.end()) - v.begin();
		int ans = n;
		for (int i = 1; i < len; i++) {
			if (v[i] <= v[i - 1] + k)
				ans -= m[v[i - 1]];
		}
		cout << ans << endl;
	}
	return 0;
}
