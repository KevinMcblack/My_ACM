#include <stdio.h>
#include <algorithm>
using namespace std;
int cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int in[1000];
		int i;
		for (i = 0; i < n; i++)
			scanf("%d", &in[i]);
		sort(in, in + n, cmp);
		
		for (i = 0; i < n; i++)
		{
			if (in[i] == 0)
			{
				printf("%d\n", in[i+1]);
				break;
			}
			if (in[i] > 0)
			{
				double res = sqrt(in[i]);
				if (res - (int)res > 0)
				{
					printf("%d\n", in[i]);
					break;
				}
			}
			else
			{
				printf("%d\n", in[i]);
				break;
			}
		}
	}
	return 0;
}
