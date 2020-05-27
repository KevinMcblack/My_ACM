#include <stdio.h>
int main(int argc, char *argv[])
{
	int t,n,p;
	int i,j;
	int a[100],k,l;
	scanf("%d",&t);
	for(l=0;l<t;l++)
		{
		scanf("%d",&n);
		scanf("%d",&p);
		for(i=0;i<p;i++)
		{
			scanf("%d",&a[i]);
		}
		k=0;
		for(i=1;i<=n;i++)
			{	
				if(i%7!=6&&i%7!=0)
				{
					for(j=0;j<p;j++)
					if(i%a[j]==0)
						{
							k++;
							break;
						}
					
				}
			}
		printf("%d\n",k);	
		}	
	
	return 0;
}