/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-16 18:49:37 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-16 20:17:08
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

const int MAXN=1e5+5;
typedef pair<int,int> P;
int n,m;
P p[MAXN];

P findPos(){
    int length=1;
    P res;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            res=make_pair(i,j);
            if(res!=p[length++]){
                return res;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int a,b;
    while(cin>>n>>m){
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            p[i]=make_pair(min(a,b),max(a,b));
        }
        if(n*(n-1)/2<=m){
            cout<<"NO"<<endl;
            continue;
        }
        
        cout<<"YES"<<endl;

        sort(p+1,p+1+m);
        P pos=findPos();
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i==pos.first){
                cout<<n-1<<" ";
            }else if(i==pos.second){
                cout<<n<<" ";
            }else{
                cout<<++cnt<<" ";
            }
        }
        cout<<endl;
        cnt=0;
        for(int i=1;i<=n;i++){
            if(i==pos.first){
                cout<<n<<" ";
            }else if(i==pos.second){
                cout<<n<<" ";
            }else{
                cout<<++cnt<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}