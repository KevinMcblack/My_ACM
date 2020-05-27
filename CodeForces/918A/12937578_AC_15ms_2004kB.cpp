#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	int a[1500];
	a[1] = 1;
	a[2] = 1;
	int k = 0;
	for (int i = 3; i <= 1000; i++)
		a[i] = a[i - 1] + a[i - 2];
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			k = 0;
			for(int j=1;j<=1000;j++)
				if (i == a[j])
				{
					printf("O");
					k = 1;
					break;
				}
			if (k == 0)
				printf("o");
		}
		printf("\n");
	}
	return 0;
}
