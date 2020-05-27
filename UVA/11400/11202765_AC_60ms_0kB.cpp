#include <iostream>
#include <algorithm>
#define min(a,b) a>b?b:a;
using namespace std;
const int maxn = 1000 + 10;
const int INF = 2000000000;
int n,d[maxn],s[maxn];
struct node{
    int v,k,c,l;
}a[maxn];
bool cmp(node a,node b) {
    return a.v < b.v;
}
int main() {
	int i,j;
    while(~scanf("%d",&n)&&n) {
        for(i=1;i<=n;i++) 
			scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
        sort(a+1,a+1+n,cmp);
        s[0] = 0;
		d[0] = 0;
        for(i=1;i<=n;i++)
			s[i] = s[i-1] + a[i].l;
        for(i=1;i<=n;i++) {
            d[i] = INF;
            for(j=0;j<i;j++) {
                d[i] = min(d[i],d[j] + (s[i]-s[j])*a[i].c + a[i].k);
            }
        }
        printf("%d\n",d[n]);
    }
    return 0;
}
