#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int a[150], b[150];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                b[l++] = a[i];
            }
            else
            {
                b[r--] = a[i];
            }
        }
        cout << b[0];
        for (int i = 1; i < n; i++)
        {
            cout << " " << b[i];
        }
        cout << endl;
    }
    return 0;
}