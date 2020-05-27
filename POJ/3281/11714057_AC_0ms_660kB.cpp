#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int inf = 0x3fffffff;
template <int N, int M>
struct Isap
{
    int top;
    int d[N], pre[N], cur[N], gap[N];
    struct Vertex{
        int head;
    } V[N];
    struct Edge{
        int v, next;
        int c, f;
    } E[M];
    void init(){
        memset(V, -1, sizeof(V));
        top = 0;
    }
    void add_edge(int u, int v, int c){
        E[top].v = v;
        E[top].c = c;
        E[top].f = 0;
        E[top].next = V[u].head;
        V[u].head = top++;
    }
    void add(int u,int v, int c){
        add_edge(u, v, c);
        add_edge(v, u, 0);
    }
    void set_d(int t){
        queue<int> Q;
        memset(d, -1, sizeof(d));
        memset(gap, 0, sizeof(gap));
        d[t] = 0;
        Q.push(t);
        while(!Q.empty()) {
            int v = Q.front(); Q.pop();
            ++gap[d[v]];
            for(int i = V[v].head; ~i; i = E[i].next) {
                int u = E[i].v;
                if(d[u] == -1) {
                    d[u] = d[v] + 1;
                    Q.push(u);
                }
            }
        }
    }
    int sap(int s, int t, int num) {
        set_d(t);
        int ans = 0, u = s;
        int flow = inf;
        memcpy(cur, V, sizeof(V));
        while(d[s] < num) {
            int &i = cur[u];
            for(; ~i; i = E[i].next) {
                int v = E[i].v;
                if(E[i].c > E[i].f && d[u] == d[v] + 1) {
                    u = v;
                    pre[v] = i;
                    flow = min(flow, E[i].c - E[i].f);
                    if(u == t) {
                        while(u != s) {
                            int j = pre[u];
                            E[j].f += flow;
                            E[j^1].f -= flow;
                            u = E[j^1].v;
                        }
                        ans += flow;
                        flow = inf;
                    }
                    break;
                }
            }
            if(i == -1) {
                if(--gap[d[u]] == 0)
                    break;
                int dmin = num - 1;
                cur[u] = V[u].head;
                for(int j = V[u].head; ~j; j = E[j].next)
                    if(E[j].c > E[j].f)
                        dmin = min(dmin, d[E[j].v]);
                d[u] = dmin + 1;
                ++gap[d[u]];
                if(u != s)
                    u = E[pre[u] ^ 1].v;
            }
        }
        return ans;
    }
};
Isap<1000, 1000000> Sap;
int main()
{
    int N,F,D;
    int s, t, num;
    while(~scanf("%d%d%d",&N,&F,&D))
    {
        t = N*2+F+D+1;
        s = 0;
        num = t+1;
        Sap.init();
        int f,d;
        for(int i = 1; i <= F; i++){//源点向各种食物连边
            Sap.add(s,i,1);
        }
        int tm;
        for(int i = 1; i <= N; i++){
            scanf("%d%d",&f,&d);
            for(int j = 1; j <= f; j++){
                scanf("%d",&tm);
                Sap.add(tm,F+i*2-1,1);//食物向喜欢它的牛连边
            }
            Sap.add(F+i*2-1,F+i*2,1);//牛拆点
            for(int j = 1; j <= d; j++){
                scanf("%d",&tm);
                Sap.add(F+i*2,2*N+F+tm,1);//牛向喜欢的饮料连边
            }
        }
        for(int i = 1; i <= D; i++){
            Sap.add(2*N+F+i,t,1);//所有饮料向汇点连边
        }
        //puts("haha");
        int ans = Sap.sap(s,t,num);
        printf("%d\n",ans);
    }
    return 0;
}