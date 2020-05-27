#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	int n, a, b;
	while (~scanf("%d%d%d", &n, &a, &b))
	{
		int i = 0, count=0;
		char in[200005];
		getchar();
		scanf("%s", in);
		for (i=0; i < n; i++)
			if (in[i] == '.')
			{
				if ((a > b&&in[i - 1] != 'A'||in[i-1]=='B')&&a > 0)
					in[i] = 'A', a--, count++;
				else if ((b >= a && in[i - 1] != 'B'||in[i-1]=='A')&&b > 0)
					in[i] = 'B', b--, count++;
			}
		printf("%d\n", count);
	}
	return 0;
}
