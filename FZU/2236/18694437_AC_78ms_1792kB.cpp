#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 100005;
const int mod = 1000000007;

int n, cnt;
int a[maxn], b[maxn], c[maxn], dp[maxn];

int lowbit(int t)
{
    return t & (-t);
}

int getsum(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans = (ans + c[x]) % mod;
        x -= lowbit(x);
    }
    return ans;
}

void update(int x, int val)
{
    while (x <= cnt)
    {
        c[x] = (c[x] + val) % mod;
        x += lowbit(x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        //离散化
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        cnt = unique(b, b + n) - b;

        memset(c, 0, sizeof(c));
        memset(dp, 0, sizeof(dp));

        //cout<<"cnt: "<<cnt<<endl;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = lower_bound(b, b + cnt, a[i]) - b + 1;
            dp[i] = (getsum(a[i] - 1) + 1) % mod;
            update(a[i], dp[i]);
            ans = (ans + dp[i]) % mod;
        }

        cout << ans << endl;
    }
    return 0;
}