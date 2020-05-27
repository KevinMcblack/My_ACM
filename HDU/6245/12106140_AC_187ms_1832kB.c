#include <stdio.h>
int main()
{
    int T,ca=0;
    scanf("%d",&T);
    while(T--)
    {
        int x,y,k,s;
        scanf("%d%d%d",&x,&y,&k);
        if(x>y)
            s=k;
        else
            s=11*k*x/(11*y+2*x);
        printf("Case #%d: %d\n",++ca,s);
    }
    return 0;
}