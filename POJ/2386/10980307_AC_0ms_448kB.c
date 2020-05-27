#include <stdio.h>
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
char map[102][102];
int m,n;
int num;
int DFS(int i,int j)
{
	int p;
	int x,y;
	map[i][j]='.';
	for(p=0;p<8;p++)
	{
		x=i+dir[p][0];
		y=j+dir[p][1];
		if(x>=0&&x<n&&y>=0&&y<m&&map[x][y]=='W')
		{
			DFS(x,y);
		}
	}
	return 1;
} 
int main(int argc, char *argv[])
{
	int i,j;
	char flag;
	num=0;
	scanf("%d%d",&n,&m);
	getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
            scanf("%c",&map[i][j]); 
        getchar();
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if(map[i][j]=='W')
				num+=DFS(i,j);
		}
	printf("%d\n",num);
	return 0;
}