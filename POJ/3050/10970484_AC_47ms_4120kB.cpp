#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int a[1000000];
int map[10][10];
int countif;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; 
int v;
int length;

void dfs(int i,int j,int bit,int sum)
{
	int x,y,p;
	if(bit==6)
	{
		a[length++]=sum;
		return ;
	}
	for(p=0;p<4;p++)
	{
		x=i+dir[p][0];
		y=j+dir[p][1];
		if(x>=0&&x<5&&y>=0&&y<5)
		{
			dfs(x,y,bit+1,sum*10+map[x][y]);
		}
	}
}
int main(int argc, char *argv[])
{
	int i,j;
	memset(a, 0, sizeof(a)); 
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&map[i][j]);
	countif=0;
	length=0;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			dfs(i,j,0,0);
	sort(a,a+length);
	for(i=0;i<length;i++)
	{
		if(a[i]!=a[i+1])
			countif++;
	}
	printf("%d\n",countif);
	return 0;
}