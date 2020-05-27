#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>

#define IO ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);

using namespace std;

int n;
int a[250000],vis[250000];


int main(int argc, char const *argv[])
{
    IO;
    while(cin>>n){
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=n;i>=1;i--){
            if(vis[i]){
                continue;
            }
            cnt++;
            int j=i;
            while(vis[a[j]]==0||a[j]!=0){
                vis[a[j]]=1;
                j=a[j];
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
