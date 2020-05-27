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
	int a[5500];
	int k;
	while (cin >> n)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			a[k]++;
		}
		int sum = 0;
		for (int i = 0; i <= 5000; i++)
		{
			if (a[i])
			{
				if (i > n)
					sum += a[i];
				else
					sum += (a[i] - 1);
			}
				
		}
		cout << sum << endl;
	}
	return 0;
}