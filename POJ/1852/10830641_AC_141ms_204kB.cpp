#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))  
#define min(a, b) ((a) < (b) ? (a) : (b)) 
int main() {
	int m, len, n, dist;
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d%d", &len, &n);
		int MIN = 0, MAX = 0;
		for (int i = 0; i<n; ++i)
		{
			scanf("%d", &dist);
			MAX = max(MAX, max(dist, len - dist));
			MIN = max(MIN, min(dist, len - dist));
		}
		printf("%d %d\n", MIN, MAX);
	}
	return 0;
}