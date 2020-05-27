#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>

#define IO ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
using namespace std;

const int maxn=1005;
int n,m,cnt;
int map[maxn][maxn],topo[maxn],c[maxn];

bool dfs(int u){
    c[u]=-1;
    for(int v=1;v<=n;v++){
        if(map[u][v]){
            if(c[v]<0){
                return false;
            }
            if(!c[v]&&!dfs(v)){
                return false;
            }
        }
    }
    c[u]=1;
    topo[--cnt]=u;
    return true;
}

bool topoSort(){
    cnt=n;
    memset(c,0,sizeof(c));
    for(int u=1;u<=n;u++){
        if(!c[u]){
            if(!dfs(u)){
                return false;
            }
        }
    }
    return true;
}

void input(){
    memset(map,0,sizeof(map));
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        map[a][b]=1;
    }
}

int main(int argc, char const *argv[])
{
    IO;
    while(cin>>n>>m&&(n||m)){
        input();
        if(topoSort()){
            cout<<topo[0];
            for(int i=1;i<n;i++){
                cout<<" "<<topo[i];
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
