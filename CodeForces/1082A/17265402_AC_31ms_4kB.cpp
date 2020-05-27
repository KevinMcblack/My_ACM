/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-18 18:38:49 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-11-21 19:32:47
 */
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
const int inf = 0x3f3f3f3f;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, d, ans = inf;
        cin >> n >> x >> y >> d;
        if (abs(y - x) % d == 0)
        {
            ans = min(ans, abs(y - x) / d);
            cout << ans << endl;
            continue;
        }
        if ((y - 1) % d == 0)
        {
            ans = min(ans, x / d + (y - 1) / d + (x % d == 0 ? 0 : 1));
        }
        if ((n - y) % d == 0)
        {
            ans = min(ans, (n - x) / d + (n - y) / d + ((n - x) % d == 0 ? 0 : 1));
        }
        if (ans == inf)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}