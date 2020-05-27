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
	char a[110];
	while (cin >> n)
	{
		int u=0, d=0, l=0, r=0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 'U')
				u++;
			else if (a[i] == 'D')
				d++;
			else if (a[i] == 'L')
				l++;
			else
				r++;
		}
		cout << 2*min(l, r) + 2*min(u, d) << endl;
	}
	return 0;
}