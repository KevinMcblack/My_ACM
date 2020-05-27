#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#define min(a,b) a>b?b:a
using namespace std;
int sum1,sum2=0;
int minimum=0x3f3f3f3f;
int main(int argc, char *argv[])
{
	int t;
	int a[15],i,j,k;
	char s[100];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		k=0;
		gets(s);
		for(i=0;i<strlen(s);i++)
			if(s[i]>='0'&&s[i]<='9')
				a[k++]=s[i]-'0';
		if(k==2)
			printf("%d\n",abs(a[0]-a[1]));
		else
		{
			do
			{
				if(a[0]==0||a[k/2]==0)
					continue;
				for(i=0;i<k/2;i++)
					sum1=sum1*10+a[i];
				for(j=k/2;j<k;j++)
					sum2=sum2*10+a[j];
				minimum=min(minimum,abs(sum1-sum2));
				sum1=sum2=0;	
			}while(next_permutation(a,a+k));
			printf("%d\n",minimum);
			sum1=sum2=0;
			minimum=0x3f3f3f3f;
		}
	}
	return 0;
}