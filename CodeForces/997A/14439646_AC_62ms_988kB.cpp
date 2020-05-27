#include <algorithm>
#include <queue>
#include <functional>
#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
string s;
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cin >> s;
	int len = s.size();
	int ans = 0;
	long long maxx = 10e18;
	int flag = 1;
	for (int i = 0; i < len; i++)
	{
		int c = s[i] - '0';
		if (c == flag) continue;
		else {
			if(c==0)
				ans++;
			flag = c;
		}
	}
	if (ans == 0)
		cout << 0 << endl;
	else
	{
		for (long long i = 1; i <= ans; i++)
		{
			long long temp = (ans - i)*x + i * y;
			maxx = min(temp, maxx);
		}
		cout << maxx << endl;
	}
	
	return 0;
}