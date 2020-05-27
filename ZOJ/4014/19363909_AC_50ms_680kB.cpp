#include <iostream>
#include <cstdio>
using namespace std;
int arr[100005];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m,A,B;
        scanf("%d%d%d%d",&n,&m,&A,&B);
        int tmp;
        long long cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&tmp);
                if(tmp<A||tmp>B)
                {
                    cnt++;
                }
            }
        }
        if(A>B)
        {
            printf("No Solution\n");
        }else{
            printf("%lld\n",cnt);
        }
    }
    
    return 0;
}