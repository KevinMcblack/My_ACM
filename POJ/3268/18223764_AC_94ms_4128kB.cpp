#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<cstdio>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int MAX = 1005;
const int INF = 0x3f3f3f3f;

struct A{
    int arcs[MAX][MAX];//权值-->路径长度 
    int arcnum;        //边的数目 
    int vexnum;        //顶点的数目
}G;

bool visit[MAX];   //顶点的访问情况
int dis[MAX];      //出发点到其余点的最短距离 
int X,v;
int ans[MAX];



//可以先从X用Dijkstra，再将道路逆置再来一下，求二者和最大即可 

//最短路Dijkstra算法 
void Dijkstra(int start){
    for(int i=1 ; i<=G.vexnum ; i++){
        dis[i] = G.arcs[start][i];
        visit[i] = false;
    }

    visit[start] = true;
    //再依次添加n-1个点,更新最短路 
    for(int i=1 ; i<=G.vexnum-1 ; i++){
        int m = INF;
        for(int j=1 ; j<=G.vexnum ; j++){
            //找到距离最小的 
            if(!visit[j] && dis[j]<m){
                m = dis[j];
                v = j;
            }
        }
        //找到最短距离的点 
        visit[v] = true;

        for(int j=1 ; j<=G.vexnum ; j++){
            //更新起始点到未访问点的最短距离 
            dis[j] = min(dis[j],dis[v]+G.arcs[v][j]);
        } 
    }
    for(int i=1 ; i<=G.vexnum ; i++){
        ans[i] += dis[i];
    }   
}
int main(void){
    while(cin>>G.vexnum>>G.arcnum>>X){
         //初始化图 
        for(int i=1 ; i<=G.vexnum ; i++){
            for(int j=1 ; j<=G.vexnum ; j++){
                G.arcs[i][j] = (i==j)?0:INF;  
            }
        }
        for(int i=1 ; i<=G.vexnum ; i++){
            ans[i] = 0;
        }
        //输入权值(路径长度) 
        for(int i=1 ; i<=G.arcnum ; i++){  
            int x,y,w;
            cin>>x>>y>>w;
            G.arcs[x][y] = w;
        }
        Dijkstra(X);
        //逆置图 
        for(int i=1 ; i<=G.vexnum ; i++){
            for(int j=1 ; j<i ; j++){
                swap(G.arcs[i][j],G.arcs[j][i]);  
            }
        }
        Dijkstra(X);

        int max=0;
        for(int i=1 ; i<=G.vexnum ; i++){
            if(ans[i] > max){
                max = ans[i];
            }
        }
        cout<<max<<endl;
    } 

    return 0;
}