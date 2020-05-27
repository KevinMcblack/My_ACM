#include <stdio.h>  
int main()
{
	int a, b, c, d;
	int i;
	int common_multiple1=28*33, common_multiple2=23*33, common_multiple3=23*28;
	int common_multiple = 28 * 33 * 23;
	for (i = 0;; i++)
		if (common_multiple1*i % 23 == 1)
			break;
	common_multiple1 *= i;
	for (i = 0;; i++)
		if (common_multiple2*i % 28 == 1)
			break;
	common_multiple2 *= i;
	for (i = 0;; i++)
		if (common_multiple3*i % 33 == 1)
			break;
	common_multiple3 *= i;
	int count = 1;
	while (scanf("%d%d%d%d", &a, &b, &c, &d))
	{
		if (a == -1 &&  b == -1 && c == -1 && d == -1)
			break;
		int res = (common_multiple1*a + common_multiple2*b + common_multiple3*c - d) % common_multiple;
		res = (res + common_multiple - 1) % common_multiple + 1;
		printf("Case %d: the next triple peak occurs in %d days.\n", count++, res);
	}
	return 0;
}