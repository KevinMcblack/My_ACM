#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	while (cin >> n)
	{
		int a[1005];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] >= 0)
			{
				if (sqrt(a[i]) == (int)sqrt(a[i]))
					continue;
				else
				{
					cout << a[i] << endl;
					break;
				}
			}
			else
			{
					cout << a[i] << endl;
					break;
			}
		}
	}
	return 0;
}