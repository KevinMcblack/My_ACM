#include <algorithm>
#include <queue>
#include <functional>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
vector<string>v;
int main()
{
	int n;
	string a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	vector<string>::iterator it;
	int ans = 0;
	for (int i=0;i<n;i++)
	{
		cin >> a;
		it = find(v.begin(), v.end(), a);
		if ( it== v.end())
			ans++;
		else
			v.erase(it);
	}
	cout << ans << endl;
	return 0;
}