#include <stdio.h>
char map[102][102];
int m,n;
int DFS(int i,int j)
{
	if(i<0||i>=n||j<0||j >= m)  
        return 0; 
	if(map[i][j]=='.')
		return 0;
	map[i][j]='.'; 
	return 1+DFS(i-1,j-1)+DFS(i-1,j)+DFS(i-1,j+1)+DFS(i,j-1)+DFS(i,j+1)+DFS(i+1,j-1)+DFS(i+1,j)+DFS(i+1,j+1);
		
} 
int main(int argc, char *argv[])
{
	int i,j,count=0;
	char flag;
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
			if(DFS(i,j)!=0)
				count++;
		}
	printf("%d\n",count);
	return 0;
}