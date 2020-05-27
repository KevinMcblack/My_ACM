#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long num;
		cin >> num;
		if (num / 10 % 10 == 1)
			printf("%lldth\n", num);
		else
		{
			int flag = num % 10;
			if (flag == 1)
				printf("%lldst\n", num);
			else if (flag == 2)
				printf("%lldnd\n", num);
			else if (flag == 3)
				printf("%lldrd\n", num);
			else
				printf("%lldth\n", num);
		}
	}
}