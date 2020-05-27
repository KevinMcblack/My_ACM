#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
char map[25][25];
bool bj[25][25]; 
int m,n;
int countif;
int dir[4][2]={-1,0,1,0,0,1,0,-1};
void DFS(int x,int y)
{
	int i,j,a,b;
	bj[x][y]=true;
	for(i=0;i<4;i++)
	{
		a=x+dir[i][0];
		b=y+dir[i][1];
		if(a>=0&&a<n&&b>=0&&b<m&&bj[a][b]!=true&&map[a][b]=='.')
		{
			countif++;
			DFS(a,b);
		}
	}
}
int main(int argc, char *argv[])
{
	int i,j,x,y;
	while(scanf("%d%d",&m,&n)!=EOF&&m&&n)
	{
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='@')
				{
					x=i;
					y=j;
				}
			}
			getchar();
		}
		memset(bj,0,sizeof(bj)); 
		countif=1;
		DFS(x,y);
		printf("%d\n",countif);
	}
	return 0;
}