#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;

int main()
{
	int n, t;
	int a[1500], b[1500];
	while (cin >> n >> t)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for(int i=0;i<t;i++)
			cin>>b[i];
		int ans = 0;
		int j = 0;
		for (int i = 0; i < t; i++)
		{
			while(j<n)
			{
				if (b[i] >= a[j])
				{
					ans++;
					j++;
					break;
				}
				j++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}