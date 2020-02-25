#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	int res = 0;
	while (cin >> n >> s)
	{
		res = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != s[i + 1])
			{
				res++;
			}
		}
		if (res + 2 > n)
		{
			cout << n << endl;
		}
		else
		{
			cout << res + 2 << endl;
		}
	}
	return 0;
}
