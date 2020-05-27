#include <iostream>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
int a[20];
int flag;
void dfs(int x, int res)
{
    if (x == n)
    {
        if (res % 360 == 0)
        {
            flag = 1;
        }
        return;
    }
    dfs(x + 1, res + a[x]);
    dfs(x + 1, res - a[x]);
}

int main()
{
    while (cin >> n)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 360 == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        if (sum & 1)
        {
            cout << "NO" << endl;
            continue;
        }
        flag = 0;
        dfs(0,0);
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}