#include <stdio.h>
int x;
int hh, mm;
int luck() {
	if (hh % 10 == 7 || mm % 10 == 7)
			return 1;
	else
			return 0;
}
int main()
{
	while (scanf("%d", &x) != -1)
	{
		scanf("%d%d", &hh, &mm);
		int count=0;
		for(count=0;!luck();count++)
		{
			mm -= x;
			if (mm < 0)
			{
				mm += 60;
				hh--;
			}
			if (hh < 0)
				hh += 24;
		}
		printf("%d\n", count);
	}
	return 0;
}