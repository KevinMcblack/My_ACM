#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

const int maxn = 200 + 10;
bool isPrime[32];
bool vis[32];
int n,A[32];

void getPrime(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=32;i++){
        if(isPrime[i]){
            for(int j=i*2;j<=32;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

void dfs(int cur){
    if(cur==n&&isPrime[A[0]+A[n-1]]){
        for(int i=0;i<n;i++){
            if(i!=0){
                cout<<" ";
            }
            cout<<A[i];
        }
        cout<<endl;
    }else{
        for(int i=2;i<=n;i++){
            if(!vis[i]&&isPrime[i+A[cur-1]]){
                A[cur]=i;
                vis[i]=1;
                dfs(cur+1);
                vis[i]=0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    getPrime();
    int k=0;
    while(cin>>n){
        if(k>0){
            cout<<endl;
        }
        cout<<"Case "<<++k<<":"<<endl;
        memset(vis,false,sizeof(vis));
        A[0]=1;
        dfs(1);
    }
    return 0;
}
