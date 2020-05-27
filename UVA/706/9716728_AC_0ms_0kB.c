#include <stdio.h>
#include <string.h>
void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
int m,h;
int main(int argc, char *argv[])
{
	int n=0,i;
	char num[9];
	while(1)
	{
		scanf("%d",&m);
		if(m==0)
			break;
		scanf("%s",num);
		n=strlen(num);
		for(h=1;h<=2*m+3;h++)
		{
			for(i=0;i<n;i++)
			{
				if(i!=0)
					printf(" ");
					switch(num[i])
				{
					case 48:zero();
						break;
					case 49:one();
						break;
					case 50:two();
						break;
					case 51:three();
						break;
					case 52:four();
						break;
					case 53:five();
						break;
					case 54:six();
						break;
					case 55:seven();
						break;
					case 56:eight();
						break;
					case 57:nine();
						break;
					default:
						break;
				}
			}
			printf("\n");
		}
		printf("\n");
		
	}
	return 0;
}
void zero()
{
	int a;
	if(h==1||h==2*m+3)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	
	else if(h==m+2)
		for(a=1;a<=m+2;a++)
			printf(" ");
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf("|");
			else
				printf(" ");
		}
}

void one()
{
	int a;
	if(h==1||h==m+2||h==2*m+3)
		for(a=1;a<=m+2;a++)
				printf(" ");
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==m+2)
				printf("|");
			else
				printf(" ");
		}
}
void two()
{
	int a;
	if(h==1||h==m+2||h==2*m+3)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	else if(h<m+2)
		for(a=1;a<=m+2;a++)
		{
			if(a==m+2)
				printf("|");
			else
				printf(" ");
		}
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==1)
				printf("|");
			else
				printf(" ");
		}
}
void three()
{
	int a;
	if(h==1||h==m+2||h==2*m+3)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==m+2)
				printf("|");
			else
				printf(" ");
		}
}
void four()
{
	int a;
	if(h==1||h==2*m+3)
		for(a=1;a<=m+2;a++)
				printf(" ");
	else if(h==m+2)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	else if(h<m+2)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf("|");
			else
				printf(" ");
		}
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==m+2)
				printf("|");
			else
				printf(" ");
		}
}
void five()
{
	int a;
	if(h==1||h==m+2||h==2*m+3)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	else if(h>m+2)
		for(a=1;a<=m+2;a++)
		{
			if(a==m+2)
				printf("|");
			else
				printf(" ");
		}
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==1)
				printf("|");
			else
				printf(" ");
		}
}
void six()
{
	int a;
	if(h==1||h==m+2||h==2*m+3)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	else if(h<m+2)
		for(a=1;a<=m+2;a++)
		{
			if(a==1)
				printf("|");
			else
				printf(" ");
		}
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf("|");
			else
				printf(" ");
		}
}
void seven()
{
	int a;
	if(h==1)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	else if(h==m+2||h==2*m+3)
		for(a=1;a<=m+2;a++)
			printf(" ");
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==m+2)
				printf("|");
			else
				printf(" ");
		}
}
void eight()
{
	int a;
	if(h==1||h==m+2||h==2*m+3)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf("|");
			else
				printf(" ");
		}
}
void nine()
{
	int a;
	if(h==1||h==m+2||h==2*m+3)
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf(" ");
			else
				printf("-");
		}
	else if(h>m+2)
		for(a=1;a<=m+2;a++)
		{
			if(a==m+2)
				printf("|");
			else
				printf(" ");
		}
	else
		for(a=1;a<=m+2;a++)
		{
			if(a==1||a==m+2)
				printf("|");
			else
				printf(" ");
		}
}