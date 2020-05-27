#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int a[10005], b[10005];
    while (cin >> n)
    {
        int ans = 0;
        int lasta = 0, lastb = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            ans += max(0, min(a[i], b[i]) - max(lasta, lastb) + 1);
            lasta = a[i];
            lastb = b[i];
            if (lasta == lastb)
            {
                lasta++;
                lastb++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}