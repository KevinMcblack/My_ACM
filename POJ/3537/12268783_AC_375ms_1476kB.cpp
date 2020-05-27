#include <stdio.h>  
#include <string.h>
#define N 2000+10
int f[N], SG[N];
int getSG(int n)
{
	if (n <= 0)
		return 0;
	if (SG[n] != -1)
		return SG[n];
	bool f[N] = { 0 };
	for (int i = 1; i <= n; i++)
		f[getSG(i - 3) ^ getSG(n - i - 2)] = 1;
	for (int i = 0;; i++)
		if (!f[i])
			return SG[n] = i;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		memset(SG, -1, sizeof(SG));
		if (getSG(n))
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}