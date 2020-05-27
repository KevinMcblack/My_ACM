#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
	char str[25];
	int a[30];
	int minn[30];
	int t;
	int n;
	int len=12;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> str;
		memset(minn, 0, sizeof(minn));
		for (int i = 0; i < len; i++)
			minn[str[i] - 'A']++;
		n -= 1;
		while(n--)
		{
			cin >> str;
			memset(a, 0, sizeof(a));
			for (int i = 0; i < len; i++)
				a[str[i] - 'A']++;
			for (int i = 0; i < 26; i++)
				minn[i] = min(minn[i], a[i]);
		}
		for (int i = 0; i < 26; i++)
		{
			while (minn[i]--)
				printf("%c", i + 'A');
		}
		printf("\n");
	}
	return 0;
}