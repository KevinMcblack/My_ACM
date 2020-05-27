#include <iostream>  
#include <cmath>  

using namespace std;
int main()
{
	int n;
	char a[150];
	cin >> n;
	int k = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1]&&a[i]!='?')
		{
			cout << "No" << endl;
			return 0;
		}
	}
	if (a[0] == '?' || a[n - 1] == '?')
	{
		cout << "Yes" << endl;
		return 0;
	}
	for (int i = 1; i < n-1; i++)
		if (a[i] == '?')
		{
			if (a[i - 1] == a[i + 1]||a[i+1]=='?')
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	cout << "No" << endl;
	return 0;
}