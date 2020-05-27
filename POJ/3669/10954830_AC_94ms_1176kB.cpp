//bfs＝队列，入队列，出队列；dfs=栈，压栈，出栈
/*
bfs是按一层一层来访问的，
所以适合有目标求最短路的步数，
你想想层层搜索每次层就代表了一步。
bfs优先访问的是兄弟节点，
只有这一层全部访问完才能访问下一层，
也就是说第几层就代表当前可以走到的位置(结点).*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define min(a,b) a>b?b:a;
using namespace std;
int map[350][350];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int mark[350][350];
struct node
{
	int x,y,step;
}temp,a;
bool operator < (const node &a,const node &b)  
{  
    return a.step>b.step;  
}
void bfs()
{
	int i;
	memset(mark,0,sizeof(mark));
	priority_queue<node>q;
	a.x=a.y=a.step=0;
	q.push(a);
	mark[0][0]=1;
	while(!q.empty())
	{
		a=q.top();
		q.pop();
		if(map[a.x][a.y]==-1)
		{
			printf("%d\n",a.step);
			return ;
		}
		for(i=0;i<4;i++)
		{
			temp.x=a.x+dir[i][0];  
            temp.y=a.y+dir[i][1];  
            temp.step=a.step+1;  
            if(temp.x>=0&&temp.y>=0&&(map[temp.x][temp.y]==-1||map[temp.x][temp.y]>temp.step))  
            {  
                if(!mark[temp.x][temp.y])  
                	q.push(temp);  
                mark[temp.x][temp.y]=1;  
            }  
		}
	}
	printf("-1\n");
}
int main(int argc, char *argv[])
{
	int n,i,j,x,y,t,nx,ny;
	while(scanf("%d",&n)!=EOF)
	{
		memset(map,-1,sizeof(map));
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&t);
		 	if(map[x][y]==-1)
		 		map[x][y]=t;
	 		else	
	 			map[x][y]=min(map[x][y],t);
			for(j=0;j<4;j++)
			{
				nx=x+dir[j][0];
				ny=y+dir[j][1];
				if(nx>=0&&ny>=0)  
	                {  
	                    if(map[nx][ny]==-1)  
	                        map[nx][ny]=t;  
	                    else  
	                        map[nx][ny]=min(t,map[nx][ny]);   
	                }  
			}
		}	
		bfs();
	}
	return 0;
}
