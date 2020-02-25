#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1e5+5;
struct node{
    int x,r,q;
}robot[maxn];
int main(int argc, char const *argv[])
{
    int n,k;
    int x;
    while(cin>>n>>k){
        for(int i=0;i<n;i++){
            cin>>robot[i].x>>robot[i].r>>robot[i].q;
        }
        int flag[maxn]={0};
        int cnt=0;
        for(int i=0;i<n;i++){
            int minn=robot[i].x-robot[i].r;
            int maxx=robot[i].x+robot[i].r;
            for(int j=i+1;j<n;j++){
                if(abs(robot[j].q-robot[i].q)<=k&&robot[j].x>=minn&&robot[j].x<=maxx)
                {
                    if(flag[i]!=flag[j]||flag[i]==0&&flag[j]==0)
                        cnt++;
                    flag[i]++;
                    flag[j]++;
                }   
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
