#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int t,n,m;
	char a[50],b[50];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		if(strcmp(a,"rat")==0)
			n=1;
		else if(strcmp(a,"ox")==0)
			n=2;
		else if(strcmp(a,"tiger")==0)
			n=3;
		else if(strcmp(a,"rabbit")==0)
			n=4;
		else if(strcmp(a,"dragon")==0)
			n=5;
		else if(strcmp(a,"snake")==0)
			n=6;
		else if(strcmp(a,"horse")==0)
			n=7;
		else if(strcmp(a,"sheep")==0)
			n=8;
		else if(strcmp(a,"monkey")==0)
			n=9;
		else if(strcmp(a,"rooster")==0)
			n=10;
		else if(strcmp(a,"dog")==0)
			n=11;
		else if(strcmp(a,"pig")==0)
			n=12;
		
		if(strcmp(b,"rat")==0)
			m=1;
		else if(strcmp(b,"ox")==0)
			m=2;
		else if(strcmp(b,"tiger")==0)
			m=3;
		else if(strcmp(b,"rabbit")==0)
			m=4;
		else if(strcmp(b,"dragon")==0)
			m=5;
		else if(strcmp(b,"snake")==0)
			m=6;
		else if(strcmp(b,"horse")==0)
			m=7;
		else if(strcmp(b,"sheep")==0)
			m=8;
		else if(strcmp(b,"monkey")==0)
			m=9;
		else if(strcmp(b,"rooster")==0)
			m=10;
		else if(strcmp(b,"dog")==0)
			m=11;
		else if(strcmp(b,"pig")==0)
			m=12;
			
		if(m==n)
			printf("12\n");
		else if(m>n)
			printf("%d\n",m-n);
		else if(m<n)
			printf("%d\n",12-n+m);
	} 
	return 0;
}