#include <stdio.h>
int main()
{
	int y, m, d;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &y, &m, &d);
		if ((d + m) % 2 == 0 || (m == 9 && d == 30) || (m == 11 && d == 30))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}