#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
#include<map>
using namespace std;
const int mod = 1e9;
struct MyStruct
{
	int start;
	int end;
	int efficitive;
}a[1050];
int dp[1050];
bool cmp(MyStruct aa, MyStruct bb)
{
	return aa.start < bb.start;
}
int main()
{
	int n, m, r;
	while (cin >> n >> m >> r)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> a[i].start >> a[i].end >> a[i].efficitive;
			a[i].end += r;
		}
		sort(a, a + m, cmp);
		int count = dp[0] = a[0].efficitive;
		for (int i = 1; i < m; i++)
		{
			dp[i] = a[i].efficitive;
			for (int j = i - 1; j >= 0; j--)
			{
				if (a[i].start - a[j].end >= 0)
					dp[i] = max(dp[i], dp[j] + a[i].efficitive);
			}
			count = max(count, dp[i]);
		}
		cout << count << endl;
	}
	return 0;
}
