#include <iostream>
#include <algorithm>
using namespace std;
static int xx = []() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
int main()
{
	int n;
	char a[1005];
	int flag = 0;
	while (cin >> n)
	{
		flag = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (n == 1)
		{
			if(a[0]=='0')
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
			continue;
		}
		if ((a[0] == '0'&&a[1] == '0')||(a[n-1]=='0'&&a[n-2]=='0'))
		{
			cout << "No" << endl;
			continue;
		}
		for (int i = 1; i < n; i++)
		{
			if (a[i] == '1')
			{
				if (a[i - 1] == '1' || a[i + 1] == '1')
				{
					flag = 1;
					break;
				}
			}
			if (a[i] == '0')
			{
				if (a[i - 1] == '0' && a[i + 1] == '0')
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}