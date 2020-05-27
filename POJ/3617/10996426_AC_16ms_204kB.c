#include <stdio.h>
int main(int argc, char *argv[])
{
	int t,i,j,countif=0;
	char a[2500];
	scanf("%d",&t);
	getchar();
	for(i=0;i<t;i++)
	{
		scanf("%c",&a[i]);
		getchar();
	}
	for(i=0,j=t-1;i<=j;)
	{
		if(a[i]<a[j])
		{
			printf("%c",a[i]);
			i++;
		}	
		else if(a[i]>a[j])
		{
			printf("%c",a[j]);
			j--;
		}
		else
		{
			int sign=0;
			int p;
			for(p=0;p<=j;p++)
			{
				if(a[i+p]>a[j-p])
				{
					sign=1;
					break;
				}
				else if(a[i+p]<a[j-p])
				{
					sign=0;
					break;
				}
			}
			if(sign)
				printf("%c",a[j--]);
			else
				printf("%c",a[i++]); 
		}
		countif++;
		if(countif%80==0)
			printf("\n");
	}		
	printf("\n");
	return 0;
}
