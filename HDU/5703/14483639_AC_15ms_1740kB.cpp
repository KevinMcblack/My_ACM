#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int n, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("1");
		while (--n)
			printf("0");
		puts("");
	}
	return 0;
}