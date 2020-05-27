#include <iostream> 
#include <string.h>
using namespace std;
int binary_serach(int key, int g[],int low,int high)
{
	while (low < high)
	{
		int mid = (high + low) / 2;
		if (key >= g[mid])
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n,i,a[100005];
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int g[100005], len = 1,j;
		g[1] = a[0];
		for (i = 1; i < n; i++)
		{
			if (g[len] < a[i])
				j = ++len;
			else
				j = binary_serach(a[i], g, 1, len + 1);
			g[j] = a[i];
		}
		printf("%d\n", len);
	}
	return 0;
}