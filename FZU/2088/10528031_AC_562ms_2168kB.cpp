#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int t,i,j,k;
	int n;
	char a[10050][200],temp[200];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",&a[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n-1;j++)
			{
				if(strcmp(a[j],a[j+1])>0)
				{
					strcpy(temp,a[j]);
					strcpy(a[j],a[j+1]);
					strcpy(a[j+1],temp);
				}
			}
		for(i=0;i<n;i++)
			printf("%s",a[i]);
		printf("\n");
	}
	return 0;
}