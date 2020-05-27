#include <iostream>
#include<algorithm>
using namespace std;
struct time{
	int left,right;
}a[25500];
bool cmp(struct time a,struct time b)
{
	if(a.left==b.left)
		return a.right>b.right;
	return a.left<b.left;
}
int main(int argc, char *argv[])
{
	int n,length,j=0,k=0;
	scanf("%d%d",&n,&length);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].left,&a[i].right);
		if(a[i].left==1)
			j=1;
		if(a[i].right==length)
			k=1;
	}
	if(j==0||k==0)
	{
		printf("-1\n");
		return 0;
	}	
	sort(a,a+n,cmp); 
	int start=a[0].right;
	int max=a[0].right;
	int count=1,sum=0,end=0;
	while(1)
	{
		while(end<n-1&&a[end+1].left<=start+1)
		{
			end++;
			if(a[end].right>max)
				max=a[end].right;
		}
		if(max!=start)
		{
			count++;
			start=max;
		}
		else
		{
			if(end==n-1)
				break;
			else	
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}