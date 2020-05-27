#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 20000 + 10;
const int INF = 1 << 30;
struct Edge{
    int from,to,cap,flow;
    Edge(){};
    Edge(int _from,int _to,int _cap,int _flow)
        :from(_from),to(_to),cap(_cap),flow(_flow){};
};

vector<Edge> edges;
vector<int> G[MAXN];
int cur[MAXN],d[MAXN];
bool vst[MAXN];

int N,M,S,T;

void init(){
    S = N + 1; T = N + 2;
    for(int i = 0;i <= T;++i)
        G[i].clear();
    edges.clear();
}

void addEdge(int from,int to,int cap){
    edges.push_back(Edge(from,to,cap,0));
    edges.push_back(Edge(to,from,0,0));
    int sz = edges.size();
    G[from].push_back(sz - 2);
    G[to].push_back(sz - 1);
}

bool BFS(){
    queue<int> Q;
    memset(vst,0,sizeof(vst));
    Q.push(S);
    vst[S] = 1;
    d[S] = 0;

    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i = 0;i < (int)G[u].size();++i){
            Edge& e = edges[G[u][i]];
            if(!vst[e.to] && e.cap > e.flow){
                d[e.to] = d[u] + 1;
                vst[e.to] = 1;
                Q.push(e.to);
            }
        }
    }

    return vst[T];
}

int DFS(int x,int a){
    if(x == T|| a == 0)
        return a;
    int flow = 0,f;
    for(int& i = cur[x];i < (int)G[x].size();++i){
        Edge& e = edges[G[x][i]];
        if(d[e.to] == d[x] + 1 && (f = DFS(e.to,min(a,e.cap - e.flow))) > 0){
            e.flow += f;
            edges[G[x][i]^1].flow -= f;
            flow += f;
            a -= f;
            if(a == 0) break;
        }
    }
    return flow;
}

int maxFlow(){
   int flow = 0;
   while(BFS()){
       memset(cur,0,sizeof(cur));
       flow += DFS(S,INF);
   }
   return flow;
}

int main()
{
//    freopen("Input.txt","r",stdin);

    while(~scanf("%d%d",&N,&M)){
        init();
        int a,b,w;
        for(int i = 1; i <= N;++i){
            scanf("%d%d",&a,&b);
            addEdge(i,T,a);
            addEdge(S,i,b);
        }

        for(int i = 0;i < M;++i){
            scanf("%d%d%d",&a,&b,&w);
            addEdge(a,b,w);                //是双向的，注意！！！！！！！！！！
            addEdge(b,a,w);
        }

        printf("%d\n",maxFlow());
    }
    return 0;
}
