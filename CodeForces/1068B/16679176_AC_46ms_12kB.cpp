#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n;
    while (cin >> n)
    {
        ll cnt = 0;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                cnt++;
                if (i * i < n)
                    cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
