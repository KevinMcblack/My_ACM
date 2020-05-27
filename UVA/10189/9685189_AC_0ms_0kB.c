#include <stdio.h>
int main(int argc, char *argv[])
{
	int i=0,j=0,k=1;
	char a[101][101];
	int m,n;
	while(scanf("%d%d",&m,&n),m!=0&&n!=0)
	{
		getchar();
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%c",&a[i][j]);
					if(a[i][j]=='.')
						a[i][j]='0';
			}
			getchar();
		}		
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				if(a[i][j]=='*')
				{
					if(a[i-1][j-1]!='*')
						a[i-1][j-1]++;
					if(a[i-1][j]!='*')
						a[i-1][j]++;
					if(a[i-1][j+1]!='*')
						a[i-1][j+1]++;
					if(a[i][j-1]!='*')
						a[i][j-1]++;
					if(a[i][j+1]!='*')
						a[i][j+1]++;
					if(a[i+1][j-1]!='*')
						a[i+1][j-1]++;
					if(a[i+1][j]!='*')
						a[i+1][j]++;
					if(a[i+1][j+1]!='*')
						a[i+1][j+1]++;
				}
		if (k!=1)
            putchar('\n');
		printf("Field #%d:\n",k);
		k++;		
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
				printf("%c",a[i][j]);
			printf("\n");
		}	
	}
	return 0;
}
