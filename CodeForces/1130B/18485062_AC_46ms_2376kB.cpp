#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int l[maxn],r[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i=1;i<=2*n;i++)
        {
            scanf("%d",&a[i]);
            if(l[a[i]]==0)
            {
                l[a[i]]=i;
            }else{
                r[a[i]]=i;
            }
        }
        long long ans=0;
        ans+=l[1]-1;
        ans+=r[1]-1;
        for(int i=2;i<=n;i++)
        {
            ans+=abs(l[i]-l[i-1]);
            ans+=abs(r[i]-r[i-1]);
        }
        cout<<ans<<endl;

    }
    return 0;
}