#include <stdio.h>
int main()
{
    double a;
    while(scanf("%lf",&a)!=EOF)
    {
        while(a>18)
        a/=18;
        if(a>9)
            printf("Ollie wins.\n");
        else
            printf("Stan wins.\n");
    }
    return 0;
}