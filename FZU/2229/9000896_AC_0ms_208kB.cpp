#include<cstdio>
int main()
{
    int a,b,c,sum=0;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        sum=3*a+2*b+6*c;
        if(sum>=60)
            printf("I passed the exam.\n");
        else
            printf("Exam was too hard.\n");
        printf("%d\n",sum);
    }
    return 0;
}