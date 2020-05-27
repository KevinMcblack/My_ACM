#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef pair<int, int> P;
const int maxn = 205;
int n;
P p[maxn];
double dist[maxn][maxn];

double dis(P p1, P p2)
{
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return sqrt((double)x * x + y * y);
}

void floyed()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > max(dist[i][k], dist[k][j]))
                {
                    dist[i][j] = max(dist[i][k], dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    int Case = 1;
    while (scanf("%d", &n) != EOF && n)
    {
        printf("Scenario #%d\n", Case++);
        printf("Frog Distance = ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &p[i].first, &p[i].second);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                dist[i][j] = dis(p[i], p[j]);
            }
        }
        floyed();
        printf("%.3lf\n\n", dist[0][1]);
    }
    return 0;
}