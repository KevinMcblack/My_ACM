#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int main(int argc, char const *argv[])
{
    int n;
    int a[maxn];
    int b[maxn];
    int c[maxn];
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int maxx = -1;
        int minn = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
        {
            b[i] = (a[i] > maxx);
            maxx = max(maxx, a[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            c[i] = (a[i] < minn);
            minn = min(minn, a[i]);
        }
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (b[i] && c[i])
            {
                v.push_back(a[i]);
            }
        }
        cout << v.size() << endl;
        if (v.size() == 0)
        {
            cout << endl;
        }
        else
        {
            cout << v[0];
            for (int i = 1; i < v.size(); i++)
            {
                cout << " " << v[i];
            }
            cout << endl;
        }
    }
    return 0;
}
