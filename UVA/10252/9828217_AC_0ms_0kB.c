#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	char a[1000],b[1000],temp;
	int i,j,n;
	while(gets(a),gets(b))
	{
	n=0;
	for(i=0;i<strlen(a);i++)
		for(j=0;j<strlen(a)-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j+1]; 
					a[j+1]=a[j];
					a[j]=temp;
				} 	
			}
	for(i=0;i<strlen(b);i++)
		for(j=0;j<strlen(b)-1;j++)
			{
				if(b[j]>b[j+1])
				{
					temp=b[j+1]; 
					b[j+1]=b[j];
					b[j]=temp;
				} 	
			}	
	for(i=0;i<strlen(a);i++)
	{
		for(j=n;j<strlen(b);j++)
		{
			if(a[i]==b[j])
			{
				printf("%c",a[i]);
				n=j+1;
				break;
			}
		}
	}
	printf("\n");
	}			
	return 0;
}