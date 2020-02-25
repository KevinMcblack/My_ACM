/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-09 20:03:12 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-09 20:27:38
 */
#include <iostream>
#include <algorithm>
typedef long long LL;
using namespace std;
LL getEdge(LL n)
{
    LL ans = 1;
    while (n--)
    {
        ans *= 10;
    }
    return ans - 1;
}
int main(int argc, char const *argv[])
{
    int n;
    LL a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        LL temp = b;
        int len = 0;
        while (temp)
        {
            temp /= 10;
            len++;
        }
        b--;
        LL res = 0;
        LL maxx = getEdge(len);
        while ((maxx - b) * len < a)
        {
            a -= (maxx - b) * len;
            res += (maxx - b);
            len++;
            b = maxx;
            maxx = getEdge(len);
        }
        if (a % len == 0)
        {
            res += a / len;
            cout << res << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
