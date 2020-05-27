/*dfs版本*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 102400;
vector<int> G[maxn], a, b;
int vis[maxn], col[maxn];
bool dfs(int u, int color)
{
    vis[u] = 1;
    col[u] = color;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v])
        {
            if (col[v] == color)
                return false;
        }
        else if (!dfs(v, -color))
            return false;
    }
    if (col[u] == 1)
        a.push_back(u);
    else
        b.push_back(u);
    return true;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    bool yes = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (G[i].empty())
                continue;
            if (!dfs(i, 1))
            {
                yes = false;
                break;
            }        
        }
    }
    if (!yes)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", a.size());
    for (int i = 0; i < a.size(); i++)
        printf("%d ", a[i]);
    printf("\n%d\n", b.size());
    for (int i = 0; i < b.size(); i++)
        printf("%d ", b[i]);
    printf("\n");
    return 0;
}
