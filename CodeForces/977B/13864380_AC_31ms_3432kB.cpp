#include <iostream>
#include<cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
static int xx = []() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
int main()
{
	string str;
	int n;
	while (cin >> n >> str)
	{
		int a[30][30] = { 0 };
		for (int i = 0; i < n - 1; i++)
			a[str[i] - 'A'][str[i + 1] - 'A']++;
		int first = 0, second = 0, maxx = 0;
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
			{
				if (maxx < a[i][j])
				{
					maxx = a[i][j];
					first = i;
					second = j;
				}
			}
		printf("%c%c\n", first + 'A', second + 'A');
	}
	return 0;
}
