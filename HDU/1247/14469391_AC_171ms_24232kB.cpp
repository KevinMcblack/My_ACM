#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
using namespace std;
char s[50005][1001];
int main()
{
	char ch1[10001],ch2[10001];
	int n=0,i=0,j,j1,j2;
	map<string,int>m;
	while(scanf("%s",s[i])!=EOF)
	{
		m[s[i]]=1;
		i++;
		n++;
	}
	for(i=0;i<n;i++)
	{
		int len=strlen(s[i]);
		for(j=0;j<len;j++)
		{
			ch1[j]=s[i][j];
			ch1[j+1]='\0';
			if(m[ch1])
			{
				for(j1=j+1,j2=0;j1<len;j1++)
				{
					ch2[j2++]=s[i][j1];
				}
				ch2[j2]='\0';
				if(m[ch2])
				{
					printf("%s\n",s[i]);
					break;
				}
			}
		}
	}
}