#include <iostream>  
#include <cmath>  
#include <string.h>
#include <cstdio>  
#include <algorithm>
#include <map>
using namespace std;

int a[1000005];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		int ra;
		int rb;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &ra);
			a[ra] = 1;
		}	
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &ra);
			if (a[ra] == 1)
				rb = ra;
		}
		printf("%d\n", rb);
	}
	return 0;
}