#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int father[100005];
int n, m;
int sum[100005];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        father[i] = i;
    }
}
int find(int p)
{
    if (p == father[p])
    {
        return p;
    }
    else
    {
        return father[p] = find(father[p]);
    }
}
int unite(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x != y)
    {
        father[y] = x;
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        //init();
        memset(sum, 0, sizeof(sum));
        int u, v, w;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            if (u == v)
            {
                continue;
            }
            sum[u] += w;
            sum[v] += w;
            if (unite(u, v))
            {
                cnt++;
            }
        }
        if (m < (n - 1) || cnt == (n - 1))
        {
            printf("%d\n", 0);
        }
        else
        {
            sort(sum + 1, sum + n + 1);
            printf("%d\n", sum[1]);
        }
    }

    return 0;
}