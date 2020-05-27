#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		char a[10005], b[10005],c[10005];
		scanf("%s", a);
		strcpy(b, a);
		strcpy(c, a);
		int len = strlen(a);
		int i,j;
		char temp;
		int count = 1;
		for (j = 0; j < len; j++)
		{
			temp = b[0];
			for (i = 0; i < len; i++)
			{
				b[i] = b[i + 1];
			}
			b[len - 1] = temp;
			if (strcmp(b, a) < 0)
				strcpy(a, b);
		}
		for (j = 0; j < len; j++)
		{
			if (strcmp(c, a) == 0)
				break;
			temp = c[0];
			for (i = 0; i < len; i++)
			{
				c[i] = c[i + 1];
			}
			c[len - 1] = temp;
			count++;
			
		}
		//printf("a %s\nc %s\n", a, c);
		printf("%d\n", count);
	}
	return 0;
}