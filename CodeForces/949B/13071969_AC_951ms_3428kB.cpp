#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
typedef  long long ll;
using namespace std;

int main()
{
	ll n, m;
	while (cin >> n >> m)
	{
		while (m--)
		{
			ll x;
			cin >> x;
			while (x % 2 == 0)
			{
				x += (n - x / 2);
			}
			cout << x / 2 + 1 << endl;
		}
	}
	return 0;
}