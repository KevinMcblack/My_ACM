#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;
int main()
{
	int h1, a1, c1;
	int h2, a2;
	while (cin >> h1 >> a1 >> c1)
	{
		cin >> h2 >> a2;
		if (a1 >= h2)
		{
			cout << 1 << endl;
			cout << "STRIKE" << endl;
			continue;
		}
		int ans = 0;
		string s[10000];
		while (1)
		{
			if (h1 > a2||a1>=h2)
			{
				s[ans] = "STRIKE";
				h2 -= a1;
				h1 -= a2;
			}
			else
			{
				s[ans] = "HEAL";
				h1 += c1;
				h1 -= a2;
			}
				ans++;
			if (h2 <= 0)
					break;
		}
		cout << ans << endl;
		for (int i = 0; i < ans; i++)
			cout << s[i] << endl;
	}
	return 0;
}