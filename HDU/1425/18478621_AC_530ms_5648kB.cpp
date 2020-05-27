#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
 
int Num[1000010];
 
int main()
{
    int N,M,d;
    while(~scanf("%d%d",&N,&M))
    {
        memset(Num,0,sizeof(Num));
        for(int i = 0; i < N; ++i)
        {
            scanf("%d",&d);
            Num[d+500000]++;
        }
        int Cnt = 0;
        for(int i = 1000000; i >= 0; --i)
        {
            while(Num[i])
            {
                Num[i]--;
                Cnt++;
                if(Cnt != M)
                    printf("%d ",i-500000);
                else
                {
                    printf("%d\n",i-500000);
                }
            }
            if(Cnt == M)
                break;
        }
    }
 
    return 0;
}
