#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 100005;
const int mod = 1000000007;

struct car
{
    int pos, v;
} a[maxn];
int maxx;
int n, cnt;
int c[maxn], dp[maxn];

int lowbit(int t)
{
    return t & (-t);
}

void update(int p,int max)
{
    while(p<=max)
    {
        c[p]++;
        p+=lowbit(p);
    }
}
 
int sum(int p)
{
    int s=0;
    while(p>0)
    {
        s+=c[p];
        p-=lowbit(p);
    }
    return s;
}

bool cmp(car a, car b)
{
    if (a.pos == b.pos)
    {
        return a.v > b.v;
    }
    else
    {
        return a.pos < b.pos;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        maxx = -1;
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].pos >> a[i].v;
            maxx = max(maxx, a[i].v);
        }
        sort(a + 1, a + 1 + n, cmp);
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            update(a[i].v, maxx);
            ans += (i - sum(a[i].v));
        }
        cout << ans << endl;
    }
    return 0;
}