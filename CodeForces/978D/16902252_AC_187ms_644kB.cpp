#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int res=0x3f3f3f3f;
        for(int j=-1;j<=1;j++){
            for(int k=-1;k<=1;k++){
                int del=a[1]+k-a[0]+j;
                int now=a[1]+k;
                int cnt=abs(j);
                int i;
                for(i=1;i<n;i++){
                    if(abs(a[i]-now)>1)
                        break;
                    else if(a[i]!=now)
                        cnt++;
                    now+=del;
                }
                if(i==n){
                    res=min(res,cnt);
                }
            }
        }
        if(res!=0x3f3f3f3f){
            cout<<res<<endl;
        }else{
            cout<<-1<<endl;
        }
        
    }
    return 0;
}
