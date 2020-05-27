#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1000010;
const int MAXM = 500000;
#define ll long long
ll a[1007], n, ans = 0x3f3f3f3f;
int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (ll j = 1; j <= n; j++)
            sum += a[j] * 2 * (abs(i - j) + abs(j - 1) + abs(1 - i));
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
