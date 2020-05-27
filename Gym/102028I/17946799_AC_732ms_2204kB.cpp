#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
int a[maxn];
ll res[maxn];
ll pre[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        pre[0]=0;
        for(int i=1;i<n;i++){
            cin>>a[i];
            pre[i]=pre[i-1]+a[i];
        }
        res[0]=0;
        ll cnt=1;
        int l=0,r=n-1;
        ll sum=0;
        while(l<=r){
            if(cnt%2==0){
                sum+=pre[r]-pre[l];
                l++,r--;
            }
            res[cnt]=res[cnt-1]+sum;
            cnt++;
        }
        for(int i=1;i<=n;i++){
            if(i!=1)
                cout<<" ";
            cout<<res[i];
        }
        cout<<endl;
    }
    return 0;
}
