#include <iostream>
#include <cstring>
using namespace std;
int m,n;
int map[25][25];
int xx[]={-1,1,0,0};
int yy[]={0,0,-1,1};
int sx,sy,ex,ey;
int step,steps;
void dfs(int x,int y)
{
	int dx,dy,vj,i,j;
	if(step>10)
		return ;
	for(i=0;i<4;i++)
	{
		dx=x+xx[i],dy=y+yy[i];
		vj=0;
		while(dx>=1&&dy>=1&&dx<=n&&dy<=m&&map[dx][dy]!=1)
		{
			if(dx==ex&&dy==ey)
				if(step<steps)
					steps=step;
			dx+=xx[i],dy+=yy[i];
			vj=1;
		}
		if(map[dx][dy]==1&&vj)
		{
			step++;
			map[dx][dy]=0;
			dfs(dx-xx[i],dy-yy[i]);
			step--;
			map[dx][dy]=1;
		}
	}		
}
int main(int argc, char *argv[])
{
	int i,j;
	while(scanf("%d%d",&m,&n)!=EOF&&m&&n)
	{
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
					sx=i,sy=j;
				if(map[i][j]==3)
					ex=i,ey=j;
			}
		step=1;
		steps=10000000;	
		dfs(sx,sy);	
		if(steps>10)
			printf("-1\n");
		else
			printf("%d\n",steps);
	}
	return 0;
}