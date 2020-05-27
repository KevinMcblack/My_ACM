#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int a[150];
		int minn = 1000000;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (k%a[i] == 0)
			{
				minn = min(k / a[i], minn);
			}	
		}
		cout << minn << endl;
	}
	return 0;
}