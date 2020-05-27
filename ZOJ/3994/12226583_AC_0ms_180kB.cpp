#include <stdio.h>
int main()
{
	int t;
	int green[1005],blue[1005];
	scanf("%d", &t);
	while (t--)
	{
		int sum1=0,sum2=0;
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&green[i]);
			sum1+=green[i];
		} 
		for(int j=0;j<n;j++)
		{
			scanf("%d",&blue[j]);
			sum2+=blue[j];
		} 
		if (sum1>sum2)
			printf("BaoBao\n");
		else
			printf("DreamGrid\n");
	}
}