#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	int n,m;
	while (cin >> n >> m)
	{
		int a[1005] = { 0 };
		int num;
		int flag = 0;
		int count = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> num;
			a[num-1]++;
			flag = 1;
			for(int j = 0; j < n;j++)
				if (a[j] == count)
				{
					flag = 0;
					break;
				}
			if (flag)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}
