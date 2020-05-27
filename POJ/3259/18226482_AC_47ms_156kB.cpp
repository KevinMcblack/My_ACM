/*
	板子题
	
	Bellman-Ford算法
	
	强！强！强！ 
*/

#include <stdio.h>
#include <string.h>
#define N 505
#define inf 100000
int dis[N]; //最小距离
int n, m;
struct Cow
{
    int x; //起点
    int y; //终点
    int w; //权值
} cow[5300];
int Bellman_ford(int m)
{
    int i, j, k, t;
    int ok;
    for (i = 1; i <= n; i++)
        dis[i] = inf;
    dis[1] = 0;
    //对每一个点进行松弛   尽可能的让路径最小
    for (i = 1; i <= n - 1; i++)
    {
        ok = 1;
        for (j = 1; j <= m; j++)
        {
            if (dis[cow[j].x] > dis[cow[j].y] + cow[j].w)
            {
                dis[cow[j].x] = dis[cow[j].y] + cow[j].w;
                ok = 0;
            }
        }
        //如果没有点进行更新  那么跳出即可  可减小时间复杂度
        if (ok)
            break;
    }
    //判断图中是否有负权值存在
    for (j = 1; j <= m; j++)
    {
        if (dis[cow[j].x] > dis[cow[j].y] + cow[j].w)
            return 0;
    }
    return 1;
}

int main()
{
    int i, j, t, x;
    int a, b, c, w;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &w);
        memset(cow, 0, sizeof(cow));
        //因为是无向图  所以需要将所有的添加进去
        for (i = 0, j = 1; j <= m; j++)
        {
            scanf("%d%d%d", &a, &b, &c);
            i++;
            cow[i].x = a;
            cow[i].y = b;
            cow[i].w = c;
            i++;
            cow[i].x = b;
            cow[i].y = a;
            cow[i].w = c;
        }
        for (j = 1; j <= w; j++)
        {
            scanf("%d%d%d", &a, &b, &c);

            i++;
            cow[i].x = a;
            cow[i].y = b;
            cow[i].w = -c;
        }
        if (Bellman_ford(i))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
