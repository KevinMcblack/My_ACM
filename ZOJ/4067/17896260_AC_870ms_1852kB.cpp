#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#define maxn 200005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

long long a[maxn];

int main(){
    int t;
    cin>>t;
    int n,m;
    while(t--){
        long long ans=0;
        cin>>n>>m;
        long long Min=INF;
        int zero=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!a[i]) zero++;
            if(Min>a[i]) Min=a[i];
        }
        if(n==m) 
            cout<<"Richman"<<endl;
        else{
            if(m==0){
                if(Min==0) cout<<"Impossible"<<endl;
                else cout<<Min-1<<endl;
            }
            else{
                int i,flag=0;
                m-=zero;
                if(m<0){
                    flag=1;
                    cout<<"Impossible"<<endl;
                    continue;
                }
                
                int co=0;
                for(i=1;i<=n&&co<m;i++){
                    if(a[i]){
                        ans+=a[i];
                        co++;
                    }
                }
                int tmp=0x3f3f3f3f;
                for(;i<=n;i++){
                    if(tmp>a[i]&&a[i]){
                        tmp=a[i];
                    }
                }
                ans+=tmp-1;
                cout<<ans<<endl;
            }
        }
    }

}