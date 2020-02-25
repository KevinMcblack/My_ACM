#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
set<string>se;
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;
		sort(s.begin(),s.end());
		s.erase(unique(s.begin(),s.end()),s.end());
		se.insert(s);
	}
	cout << se.size() << endl;
	return 0;
}