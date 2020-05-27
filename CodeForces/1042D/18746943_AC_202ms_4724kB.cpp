#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 200005;
const int mod = 1000000007;
typedef long long ll;

int n;
ll t;
ll a[maxn], b[maxn], sum[maxn];

ll lowbit(int x)
{
    return x & (-x);
}

void add(ll x)
{
    while (x <= n+1)
    {
        sum[x]++;
        x += lowbit(x);
    }
}

ll getsum(ll x)
{
    ll res = 0;
    while (x > 0)
    {
        res += sum[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> t)
    {
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            a[i] += a[i - 1];
            b[i] = a[i];
        }
        sort(b, b + n + 1);
        ll ans=0;
        for (int i = 1; i <= n; i++)
        {
            add(lower_bound(b, b + 1 + n, a[i - 1]) - b + 1);
            ll temp = i - getsum(lower_bound(b, b + n + 1, a[i] - t + 1) - b);
            ans += temp;
        }
        cout << ans << endl;
    }
    return 0;
}