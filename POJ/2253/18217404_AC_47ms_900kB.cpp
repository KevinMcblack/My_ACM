#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
const int maxn = 205;
int n;
int X[maxn], Y[maxn];
int cnt;
int father[maxn * maxn];
struct node
{
    int x, y;
    double dis;
} map[maxn * maxn];

bool cmp(node a, node b)
{
    return a.dis < b.dis;
}

void init()
{
    for (int i = 0; i <= n * n; i++)
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

double kruskal()
{
    int res = 0;
    sort(map, map + cnt, cmp);
    for (int i = 0; i < cnt; i++)
    {
        if (unite(map[i].x, map[i].y))
        {
            if (find(0) == find(1))
            {
                return map[i].dis;
            }
        }
    }
}

double getlen(int i, int j)
{
    int x=X[i] - X[j];
    int y=Y[i] - Y[j];
    return sqrt(double(x*x+y*y));
}

void input()
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &X[i], &Y[i]);
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            map[cnt].x = i;
            map[cnt].y = j;
            map[cnt++].dis = getlen(i, j);
        }
    }
}

int main()
{
    int Case = 1;
    while (scanf("%d", &n) != EOF&&n)
    {
        printf("Scenario #%d\n", Case++);
        printf("Frog Distance = ");
        input();
        init();
        printf("%.3lf\n\n", kruskal());
    }
    return 0;
}