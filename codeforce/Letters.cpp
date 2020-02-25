#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2*1e5+5;
long long a[maxn];
int main(int argc, char const *argv[])
{
    long long n,m;
    long long t;
    while(cin>>n>>m){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>t;
            a[i]=a[i-1]+t;
        }
        long long p,su;
        for(int i=0;i<m;i++)
        {
            cin>>p;
            su=lower_bound(a+1,a+1+n,p)-a;
            cout<<su<<" "<<p-a[su-1]<<endl;
        }
    }
    return 0;
}
