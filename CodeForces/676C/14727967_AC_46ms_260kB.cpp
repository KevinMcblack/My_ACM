#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;
const int mod = 1e6;
const int inf = 0x3f3f3f3f;
int n, k;
string s;
int res(char x)
{
	int l = 0, r = 0;
	int ans = 0;
	int cnt = 0;
	while (l < n&&r < n)
	{
		while ((s[r] == x || cnt < k)&&r<n)
		{
			if (s[r] != x)
				cnt++;
			r++;
		}
		ans = max(ans, r - l);
		while (l <= r&&s[l]==x)
			l++;
		l++;
		cnt--;
	}
	return ans;
}
int main()
{
	while (cin >> n >> k)
	{
		cin >> s;
		cout << max(res('a'),res('b')) << endl;
	}
	return 0;
}
