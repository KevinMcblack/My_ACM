#include <iostream>
#include <algorithm>

using namespace std;

int father[100005*2];
int last[100005*2];
int n, m;
//并查集
void init()
{
    for (int i = 0; i <= (2*m); i++)
    {
        father[i] = i;
    }
}
int find(int p)
{
    if (father[p] == p)
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
    return 0;
}
int unlocked[100005*2];
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &unlocked[i]);
        }
        int t;
        int tmp;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &t);
            for (int j = 1; j <= t; j++)
            {
                scanf("%d",&tmp);
                if (last[tmp] == 0)
                {
                    last[tmp] = i;
                }
                else
                {
                    //i是开 i+m是关
                    if (unlocked[tmp])
                    {
                        unite(last[tmp], i);
                        unite(last[tmp] + m, i + m);
                    }
                    else
                    {
                        unite(last[tmp] + m, i);
                        unite(last[tmp], i + m);
                    }
                }
            }
        }
        int flag = 0;
        for (int i = 1; i <= m; i++)
        {
            if (find(i)==find(i+m))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}