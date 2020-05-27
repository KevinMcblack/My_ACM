#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <cmath>

using namespace std;

int n, a[32005], val[32005];

 
int lowbit(int x)
{
    return x&(-x);
}

void update(int p, int k)
{
    while (p <= 32005)
    {
        a[p] += k;
        p += lowbit(p);
    }
}

int sum(int x)
{
    int total = 0;
    while (x > 0)
    {
        total += a[x];
        x -= lowbit(x);
    }
    return total;
}

int main()
{
    int i, x, y;
    while (scanf("%d", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        memset(val, 0, sizeof(val));
        for (i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            x++;
            val[sum(x)]++;
            update(x, 1);
        }
        for (i = 0; i < n; i++)
        {
            printf("%d\n", val[i]);
        }
    }
    return 0;
}