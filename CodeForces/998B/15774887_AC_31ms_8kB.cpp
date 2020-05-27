#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    int a[105], b[105];
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int odd = 0, even = 0;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0)
            {
                odd++;
            }
            else
            {
                even++;
            }
            if (odd == even && i != n - 1)
            {
                //cout<<a[i + 1] - a[i]<<endl;
                b[p++] = abs(a[i + 1] - a[i]);
            }
        }
        sort(b, b + p);
        int ans = 0;
        for (int i = 0; i < p; i++)
        {
            k -= b[i];
            if (k >= 0)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
