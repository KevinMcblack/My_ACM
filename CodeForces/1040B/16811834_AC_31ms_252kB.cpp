#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k, d, i, q, r;
    cin >> n >> k;
    d = 2 * k + 1;
    q = n / d;
    r = n % d;
    if (r != 0)
        q++;
    else
        r = 2 * k;
    cout << q << endl;
    for (i = 1 + r / 2; i <= n; i += d)
        cout << i << " ";
    cout<<endl;
    return 0;
}