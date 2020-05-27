/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-16 18:49:37 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-16 19:15:13
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

const int MAXN=2e5+5;
const int INF=0x3f3f3f3f;
int n,x,y;
char s[MAXN];
int pre[MAXN][2];

bool check(int mid){
    for(int i=1;i+mid-1<=n;i++){
        int xx=pre[n][0]-pre[i+mid-1][0]+pre[i-1][0];
        int yy=pre[n][1]-pre[i+mid-1][1]+pre[i-1][1];
        
        int tx=abs(x-xx);
        int ty=abs(y-yy);

        if(tx+ty<=mid&&(mid-tx-ty)%2==0){
            return true;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    while(cin>>n){
        scanf("%s",s+1);
        cin>>x>>y;
        pre[0][0]=0;
        pre[0][1]=0;
        
        for(int i=1;i<=n;i++){
            pre[i][0]=pre[i-1][0];
            pre[i][1]=pre[i-1][1];
            if(s[i]=='U'){
                pre[i][1]++;
            }else if(s[i]=='D'){
                pre[i][1]--;
            }else if(s[i]=='R'){
                pre[i][0]++;
            }else if(s[i]=='L'){
                pre[i][0]--;
            }
        }
        int l=0,r=n;
        int ans=INF;
        while(l<=r){
            int mid=(r+l)>>1;
            if(check(mid)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        if(ans==INF){
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}