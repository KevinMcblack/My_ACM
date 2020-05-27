#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#include <vector> 
#define MAX_V 1500
#define inf 0x3f3f3f3f  
using namespace std;
struct edge{
	int to,cap,rev;
};
vector <edge> G[MAX_V];
bool used[MAX_V];
void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{
	if(v==t)return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(!used[e.to]&&e.cap>0)
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	} 
	return 0;
}
int max_flow(int s,int t)
{
	int flow=0;
	for(;;)
	{
		memset(used,0,sizeof(used));
		int f=dfs(s,t,inf);
		if(f<=0)return flow;
		flow+=f;
	}
}
int main(int argc, char *argv[])
{

		int m,n;
		int u,v,w;
		while(scanf("%d%d",&n,&m)!=EOF){	
		for (int s=1;s<=n;s++)  
            G[s].clear();  
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			add_edge(u,v,w);
		}
		printf("%d\n",max_flow(1,m));	
		}
			

	return 0;
}