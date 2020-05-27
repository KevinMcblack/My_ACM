#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const int maxn = 10007;
int a[maxn];

int main()
{
	a[0] = 0;
	for (int i = 1; i <= 10007; i++)
	{
		if ((i + 1867) % 4 == 0 && (i + 1867) % 100 != 0||(i + 1867)%400==0)
			a[i] = a[i-1] + 2;
		else
			a[i] = a[i-1] + 1;
	}
	int n;
	while (~scanf("%d", &n))
	{
		if (a[n] % 7 == 0)
			printf("Sunday\n");
		else if (a[n] % 7 == 1)
			printf("Monday\n");
		else if (a[n] % 7 == 2)
			printf("Tuesday\n");
		else if (a[n] % 7 == 3)
			printf("Wednesday\n");
		else if (a[n] % 7 == 4)
			printf("Thursday\n");
		else if (a[n] % 7 == 5)
			printf("Friday\n");
		else if (a[n] % 7 == 6)
			printf("Saturday\n");
	}
	return 0;
}
