#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
map<int, int> m, p;
const int maxn = 5e5 + 5;
string s;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll ans = 0;
    for (int k = 0; k < n; k++)
    {
        cin >> s;
        int len = s.size();
        int x = 0;
        int minn = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                x++;
            }
            else if (s[i] == ')')
            {
                x--;
            }
            minn = min(minn, x);
        }
        if (minn == 0 && x == 0)
        {
            ans++;
        }
        else if (minn == 0)
        {
            m[x]++;
        }
        else if (minn < 0 && minn == x)
        {
            p[-x]++;
        }
    }
    ans /= 2;
    for (int i = 0; i < maxn; i++)
    {
        ans += min(p[i], m[i]);
    }
    cout << ans << endl;
    return 0;
}