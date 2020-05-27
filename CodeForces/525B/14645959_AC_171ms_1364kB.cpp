#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;
int a[220000];
int main()
{
	string s;
	int b;
	while (cin >> s)
	{
		memset(a, 0, sizeof(a));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> b;
			a[b - 1]++;
		}
		int len = s.size();
		for (int i = 1; i <= len / 2; i++)
		{
			a[i] += a[i - 1];
		}
		for (int i = 0; i < len / 2; i++)
		{
			if (a[i] &1)
			{
				char temp = s[i];
				s[i] = s[len - 1 - i];
				s[len - 1 - i] = temp;
			}
		}
		cout << s << endl;
	}
	return 0;
}