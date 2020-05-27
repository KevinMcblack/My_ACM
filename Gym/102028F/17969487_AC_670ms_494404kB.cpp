#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 10000 + 50;

int n, m;
char map[maxn][maxn];
int vis[maxn][maxn];
int startX, startY;
int endX, endY;
int dx[6] = {1, 1, -1, -1, 2, -2};
int dy[6] = {3, -3, 3, -3, 0, 0};

struct status
{
    int x, y, step;
};

int bfs()
{
    queue<status> q;
    q.push(status{startX, startY, 1});
    vis[startX][startY] = 0;
    while (!q.empty())
    {
        status cur = q.front();
        q.pop();
        if (cur.x == endX && cur.y == endY)
        {
            return cur.step;
        }
        for (int i = 0; i < 6; i++) 
        {
            int nextX = cur.x + dx[i], nextY = cur.y + dy[i];
            //判断可行性
            if (nextX < n && nextX >= 0 && nextY >= 0 && nextY < m && map[nextX][nextY] == ' ')
            {
                int nnx = nextX + dx[i], nny = nextY + dy[i];
                if (nnx < n && nnx >= 0 && nny >= 0 && nny < m)
                {
                    if (cur.step + 1 < vis[nnx][nny])
                    {
                        q.push(status{nnx, nny, cur.step + 1});
                        vis[nnx][nny] = cur.step + 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        getchar();
        n = a * 4 + 3, m = b * 6 + 3;
        for (int i = 0; i < n; i++)
        {
            fgets(map[i], maxn, stdin);
            int len = strlen(map[i]);
            if (map[i][len - 1] == '\n')
            {
                map[i][len - 1] = '\0';
            }
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = INF;
                if (map[i][j] == 'S')
                {
                    startX = i;
                    startY = j;
                }
                if (map[i][j] == 'T')
                {
                    endX = i;
                    endY = j;
                }
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}