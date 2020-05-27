#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int vis[2000005];

int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        memset(vis, 0, sizeof(vis));
        if (a < 0 && b < 0 && c < 0 && d < 0 || a > 0 && b > 0 && c > 0 && d > 0)
        {
            cout << 0 << endl;
            continue;
        }
        for (int x1 = 1; x1 <= 100; x1++)
        {
            for (int x2 = 1; x2 <= 100; x2++)
            {
                vis[1000000 + a * x1 * x1 + b * x2 * x2]++;
            }
        }
        ll ans = 0;
        for (int x3 = 1; x3 <= 100; x3++)
        {
            for (int x4 = 1; x4 <= 100; x4++)
            {
                ans += vis[1000000 - c * x3 * x3 - d * x4 * x4];
            }
        }
        cout << ans * 16 << endl;
    }
    return 0;
}