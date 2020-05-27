#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int inn[20], a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &inn[i]);
			if (inn[i] == 1)
				a++;
			else if (inn[i] == 2)
				b++;
		}
		if (a < b)
			printf("Tohru\n");
		else if (a > b)
			printf("Kobayashi\n");
		else
			printf("Draw\n");
	}
	return 0;
}
