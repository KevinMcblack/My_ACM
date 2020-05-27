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
	int n;
	while (cin >> n)
	{
		long long a[355][355];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cin >> a[i][j];
		}
		for (int i = n - 1; i >= 1; i--)
		{
			for (int j = 0; j <= i; j++)
				a[i - 1][j] += max(a[i][j], a[i][j + 1]);
		}
		cout << a[0][0] << endl;
	}
	return 0;
}