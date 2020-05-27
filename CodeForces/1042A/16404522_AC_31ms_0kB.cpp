#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,maxans,sum,minans;
int a[200];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        maxans=max(maxans,a[i]);
        sum+=a[i];
    }
    sum+=m;
    minans=max(maxans,(sum+n-1)/n);
    printf("%d %d",minans,maxans+m);
    return 0;
}