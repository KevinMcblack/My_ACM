#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200005;
long long a[N],b[N],aa[N],bb[N];
long long n,d,l1,l2,p1,p2,rnk;
multiset<long long> st;
multiset<long long>::iterator it;
int main ()
{
    scanf("%lld%lld",&n,&d); 
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    long long forc=a[d]+b[1];
    for(int i=1;i<=n;i++) if(i!=d) aa[++l1]=a[i];
    for(int i=n;i>=2;i--) st.insert(b[i]); rnk=1;
    for(int i=1;i<=l1;i++) 
    {
        if(aa[i]>forc) rnk++,it=st.end(),it--,st.erase(it);
        else
        {
            if(aa[i]+(*(st.begin()))>forc) {rnk++,it=st.end(),it--,st.erase(it);continue;}
            long long res=forc-aa[i];it=st.upper_bound(res);
            it--; st.erase(it);
        }
    }
    printf("%lld",rnk);
    return 0;
}