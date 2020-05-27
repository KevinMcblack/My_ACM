#include <iostream> 
#include <cstring> 
using namespace std;
#define max(a,b) (a)>(b)?(a):(b) 
struct rob {
	int money;
	double rate;
}a[150];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		double p;
		int n;
		int sum = 0;
		scanf("%lf%d", &p, &n);
		for (int i = 0; i < n; i++)
		{
				scanf("%d%lf", &a[i].money, &a[i].rate);
				sum += a[i].money;
		}
		double dp[10050];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = sum; j >= a[i].money; j--)
				dp[j] = max(dp[j], dp[j - a[i].money] * (1 - a[i].rate));
		for (int i = sum; i >= 0; i--)
			if (dp[i] > 1 - p)
			{
				printf("%d\n", i); 
				break;
			}
	}
	return 0;
}