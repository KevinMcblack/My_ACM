#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
const int maxn = 1e5 + 5;

int main()
{
	string s;
	cin >> s;	
	int len = s.size();
	int ans0 = 0, ans1 = 0, ans2 = 0;
	for (int i = 0; i < len; i++)
	{
		ans0 += (s[i] == '0');
		ans1 += (s[i] == '1');
		ans2 += (s[i] == '2');
	}
	if (ans0 == 0 || ans2 == 0)
	{
		sort(s.begin(), s.end());
		cout << s << endl;
		return 0;
	}
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '0')
			cout << 0;
		else if (s[i] == '2'&&ans1)
		{
			while (ans1)
			{
				cout << 1;
				ans1--;
			}
			cout << 2;
		}
		else
		{
			if (s[i] == '2')
				cout << 2;
			if (s[i] == '1')
				continue;
		}
	}
	return 0;
}