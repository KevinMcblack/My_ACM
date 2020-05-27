#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
const int maxn = 1e4 + 5;

#define INF 0x3f3f3f3f
int n, m;
int father[maxn];
struct node
{
    int x, y, d;
} map[maxn];
bool cmp(node a, node b)
{
    return a.d < b.d;
}
void init()
{
    int i;
    for (int i = 1; i <= n; i++)
        father[i] = i;
}
int find(int p)
{
    if (father[p] == p)
        return p;
    return father[p] = find(father[p]);
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
int kruskal(int n, int m)
{
    int cnt = 0;
    sort(map, map + m, cmp);
    int ans = INF;
    for (int i = 0; i < m; i++)
    {
        cnt = 0;
        init();
        for (int j = i; j < m; j++)
        {
            if (unite(map[j].x, map[j].y))
            {
                cnt++;
            }
            if (cnt == n - 1)
            {
                ans = min(ans, map[j].d - map[i].d);
                break;
            }
        }
    }
    if(ans==INF){
        return -1;
    }
    return ans;
}
int main()
{
    while (cin >> n >> m && (m || n))
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &map[i].x, &map[i].y, &map[i].d);
        }
        if (m < n - 1)
        {
            cout << -1 << endl;
            continue;
        }
        cout << kruskal(n, m) << endl;
    }
    return 0;
}