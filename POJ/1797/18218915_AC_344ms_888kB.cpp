#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
const int maxn = (1000*1001)/2;
int n,m;
int father[maxn];
struct node{
    int x,y,w;
}map[maxn];

void init(){
    for(int i=0;i<m;i++){
        father[i]=i;
    }
}

bool cmp(node a,node b){
    return a.w>b.w;
}

int find(int p){
    if(father[p]==p){
        return p;
    }
    return father[p]=find(father[p]);
}   

int unite(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x!=y){
        father[y]=x;
        return 1;
    }
    return 0;
}

int kruskal(){
    sort(map,map+m,cmp);
    for(int i=0;i<m;i++){
        if(unite(map[i].x,map[i].y)){
            if(find(1)==find(n)){
                return map[i].w;
            }
        }
    }
}

void input()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&map[i].x,&map[i].y,&map[i].w);
    }
}

int main()
{
    int Case = 1;
    int t;
    scanf("%d",&t);
    while(t--)
    {   
        input();
        init();
        printf("Scenario #%d:\n", Case++);
        printf("%d\n\n", kruskal());
    }
    return 0;
}