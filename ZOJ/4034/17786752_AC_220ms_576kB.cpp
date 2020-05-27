#include<stdio.h>
#include<string.h>
 
int a[100005];
 
int main()
{
    int t,m,n,k,p;
    scanf("%d",&t);
    while(t--)
    {
        char str[3];
        scanf("%d%d",&n,&m);
        p = -1;
        a[n] = 3*m+1;                   //防止最后一个数是白板
        for(int i = 0; i < n; i++)
        {
            scanf("%s",str);
            if(str[0] == 'W')
                {
                    p = i;
                    continue;
                }
            scanf("%d",&k);
            if(str[0] == 'C')
                a[i] = k;
            else if(str[0] == 'B')
                a[i] = m+k;
            else
                a[i] = 2*m+k;
        }
        if(n == 1)
            printf("%d\n",3*m);              //只有一个数
        else if(a[0] > a[1] && p != 1)       //当第一个数比第二个数大时，并且第二个数不是白板，输出1
            printf("1\n");
        else if(p == -1)                     //没有白板的情况
            printf("%d\n",3*m-n+1);
        else
        {
            if(p == 0)                      //第一个数是白板的情况
                printf("%d\n",a[1]);
            else if(p == 1)                 //第二个数是白板的情况
                printf("%d\n",a[2]-a[0]);
            else                            //第p个数是白板的情况(p>1),等于其后一个数减去前一个数再减一
                printf("%d\n",a[p+1]-a[p-1]-1);
        }
    }
    return 0;//
}
