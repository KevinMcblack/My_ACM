#include <stdio.h>
int main(int argc, char *argv[])
{
	int n,i,j;
	char a[10050];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%c",&a[i]);
			if(a[i]>='0'&&a[i]<='9')
                a[i]=1;
            else
                a[i]=0;
		}	
		for(j=0,i=0;i<n;i=i+5)
		{
			a[j++]=a[i]*2*2*2*2+a[i+1]*2*2*2+a[i+2]*2*2+a[i+3]*2+a[i+4]+'A';
		}
		for(i=0;i<j;i++)
			printf("%c",a[i]);
		printf("\n");
	} 
	return 0;
}