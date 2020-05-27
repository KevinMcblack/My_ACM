#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int father[100005];
int a, b, n;
int pi[100005];
map<int, int> M;
void init()
{
    for (int i = 0; i <= n + 1; i++)
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
int main()
{
    while (~scanf("%d%d%d", &n, &a, &b))
    {
        init();
        M.clear();
        long long sum = 0;
        int maxx = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &pi[i]);
            M[pi[i]] = i;
            maxx = max(maxx, pi[i]);
        }
        if (maxx > max(a, b))
        {
            printf("NO\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (M[a - pi[i]])
            {
                unite(i, M[a - pi[i]]);
            }
            else
            {
                unite(i, 0);
            }
            if (M[b - pi[i]])
            {
                unite(i, M[b - pi[i]]);
            }
            else
            {
                unite(i, n + 1);
            }
        }
        int B = find(0);
        int A = find(n + 1);
        if (A != B)
        {
            printf("YES\n");
            for (int i = 1; i <= n; i++)
            {
                if (i != 1)
                {
                    printf(" ");
                }
                if (find(i) == A)
                {
                    printf("0");
                }
                else
                {
                    printf("1");
                }
            }
            printf("\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}