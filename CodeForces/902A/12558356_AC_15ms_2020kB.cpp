#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
#include <math.h>
using namespace std;
struct dis {
	int a;
	int b;
}arr[110];
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int i;
		for (i = 0; i < n; i++)
			scanf("%d%d", &arr[i].a, &arr[i].b);
		int flag = 0;
		if (arr[0].b >= m)
			flag = 1;
		for (i = 1; i < n; i++)
		{
			if (arr[i].a > arr[i - 1].b)
				break;
			if (arr[i].b < arr[i - 1].b)
				arr[i].b = arr[i - 1].b;
			if (arr[i].b >= m)
			{
				flag = 1;
				break;
			}	
		}
		if (arr[0].a > 0)
			flag = 0;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
