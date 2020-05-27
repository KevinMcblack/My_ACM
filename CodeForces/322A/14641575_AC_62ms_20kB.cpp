#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int a[1000] = { 0 };
		if (n == 1 || m == 1)
		{
			cout << n + m - 1 << endl;
			if(n>m)
				for (int i = 1; i <= max(n, m); i++)
				{
					cout << i << " " << 1 << endl;
				}
			else
				for (int i = 1; i <= max(n, m); i++)
				{
					cout << 1 << " " << i << endl;
				}
		}
		else
		{
			cout << n + m - 1 << endl;
			for(int i=1;i<=n;i++)
				for (int j = 1; j <= m; j++)
				{
					a[i + j] = 1;
				}
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
				{
					if (a[i + j] == 1||a[i+j]==0)
					cout << i << " " << j << endl;
					if (a[i + j] == 1)
						a[i + j] = 2;
				}
		}
	}
	return 0;
}
