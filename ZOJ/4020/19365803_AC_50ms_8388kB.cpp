#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn=1e5+5;
int n,m;
vector<int> vec[maxn];
vector<bool> vis[maxn];
int sx,sy,ex,ey;
struct Node{
    int x,y,dis;
};
int dirx[]={0,0,-1,1};
int diry[]={-1,1,0,0};

bool judge(int x,int y)
{
    if(x<1||y<1||x>n||y>m||vis[x][y])
    {
        return false;
    }else{
        return true;
    }
}

int bfs()
{
    queue<Node> q;
    Node start;
    start.x=sx,start.y=sy,start.dis=0;
    q.push(start);
    vis[sx][sy]=true;
    while(!q.empty())
    {
        start=q.front();
        q.pop();
        int state=vec[start.x][start.y];
        if(start.dis&1)
        {   
            if(state){
                state=0;
            }else{
                state=1;
            }
        }
        Node tmp;
        if(state==0)
        {
            for(int i=2;i<4;i++)
            {
                tmp.x=start.x+dirx[i];
                tmp.y=start.y+diry[i];
                tmp.dis=start.dis+1;
                if(tmp.x==ex&&tmp.y==ey){
                    return tmp.dis;
                }
                if(judge(tmp.x,tmp.y))
                {
                    vis[tmp.x][tmp.y]=true;
                    q.push(tmp);
                }
            }
        }else{
            for(int i=0;i<2;i++)
            {
                tmp.x=start.x+dirx[i];
                tmp.y=start.y+diry[i];
                tmp.dis=start.dis+1;
                if(tmp.x==ex&&tmp.y==ey){
                    return tmp.dis;
                }
                if(judge(tmp.x,tmp.y))
                {
                    vis[tmp.x][tmp.y]=true;
                    q.push(tmp);
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&n,&m); 
       for(int i=1;i<=n;i++)
       {
           vec[i].clear();
           vis[i].clear();
       }    
       int temp;
       for(int i=1;i<=n;i++)
       {
           vec[i].push_back(0);
           vis[i].push_back(false);
           for(int j=1;j<=m;j++)
           {
               scanf("%d",&temp);
               vec[i].push_back(temp);
               vis[i].push_back(false);
           }
       }
       scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
       if(sx==ex&&sy==ey)
       {
           printf("0\n");
       }else{
           printf("%d\n",bfs());
       }
    }
    return 0;
}