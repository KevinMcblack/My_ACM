#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> V[100100];
int vis[100100];
ll num0;//顶点数
ll num1;
void dfs(int x, int step)
{
    for (int i = 0; i < V[x].size(); i++)
    {
        if (!vis[V[x][i]])
        {
            vis[V[x][i]] = 1;
            if (step % 2 == 1)
                num0++;
            else
                num1++;
            dfs(V[x][i], step + 1);
        }
    }
}
int main()
{
    int n, a, b;
    scanf("%d", &n);
    for (int k = 0; k < n - 1; k++)
    {
        scanf("%d%d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    num0 = 1;
    num1 = 0;
    vis[1] = 1;
    dfs(1, 0);
    cout << num0 * num1 - (n - 1) << endl;
    return 0;
}