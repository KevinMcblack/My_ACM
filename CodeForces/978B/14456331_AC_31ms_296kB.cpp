#include <algorithm>
#include <queue>
#include <functional>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main()
{
	char a[150];
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 2; i < n; i++)
	{
		if (a[i] ==  'x'&&a[i-1]=='x'&&a[i-2]=='x')
			ans++;
	}
	cout << ans << endl;
	return 0;
}
