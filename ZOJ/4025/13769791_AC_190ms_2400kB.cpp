#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
using namespace std;
map <int, int> m;
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int d[100005];
		int s[100005];
		m.clear();
		for (int i = 0; i < n; i++)
			scanf("%d", &d[i]);
		for (int i = 0; i < n; i++) {
			scanf("%d", &s[i]);
			m[s[i]-d[i]]++;
		}
		map<int, int>::iterator it;
		int maxx = -1;
		for (it = m.begin(); it != m.end(); it++)
		{
			maxx = max(maxx, it->second);
		}
		cout << maxx << endl;
	}
	return 0;
}