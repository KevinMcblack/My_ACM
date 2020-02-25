#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
string s1[maxn], s2[maxn];
int a[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> s1[i] >> s2[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		string minn;
		int flag = 0;
		minn = min(s1[a[0] - 1], s2[a[0] - 1]);
		for (int i = 0; i < n - 1; i++)
		{
			if (minn < s1[a[i + 1] - 1] && minn < s2[a[i + 1] - 1])
			{
				minn = min(s1[a[i + 1] - 1], s2[a[i + 1] - 1]);
			}
			else if (minn < s1[a[i + 1] - 1])
			{
				minn = s1[a[i + 1] - 1];
			}
			else if (minn < s2[a[i + 1] - 1])
			{
				minn = s2[a[i + 1] - 1];
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}
