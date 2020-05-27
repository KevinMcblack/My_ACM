#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 1)
		{
			printf("1\n");
			continue;
		}
		else if (n == 2)
		{
			printf("2\n");
			continue;
		}	
		int j = 2;
		int count = 0;
		int sum = 2;
		for (int i = 2; i < n; i++)
		{
			sum += j;
			count++;
			if (count % 2 == 0)
				j++;
		}
		printf("%d\n", sum);
	}
    return 0;
}