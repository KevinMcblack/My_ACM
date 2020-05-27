#include <stdio.h>  
int main()
{
	long long p;
	while (scanf("%lld", &p) &&p)
	{
		long long a = p, res = p;
		for (long long i = 2; i*i <= a; i++)
		{
			if (a%i == 0)
			{
				res =res/ i*(i - 1);
				while (a%i == 0)
				{
					a /= i;
				}
			}
		}
		if (a > 1)
			res = res/a*(a - 1);
		printf("%lld\n", res);
	}
	return 0;
}