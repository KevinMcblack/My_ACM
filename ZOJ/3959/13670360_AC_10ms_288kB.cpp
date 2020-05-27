#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <set>
#include <math.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	int a[150];
	int n;
	while (t--)
	{
		int flag = 1;
		int count = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] <= 0)
				flag = 0;
			if (a[i] == 1)
				count++;
			if (a[i] < 1)
				flag = 0;
		}
		if (n < 10 || n>13)
		{
			printf("No\n");
			continue;
		}
		if (count < 2)
			flag = 0;
		if (flag == 0)
		{
			printf("No\n");
			continue;
		}
		sort(a, a + n);
		for (int i = 1; i < n-1; i++)
		{
			if (abs(a[i] - a[i - 1]) > 2)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
		{
			printf("No\n");
			continue;
		}
		else
			printf("Yes\n");
	}
	return 0;
}
