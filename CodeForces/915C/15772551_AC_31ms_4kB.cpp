#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
    string a, b, c;
    while (cin >> a >> b)
    {
        sort(a.begin(), a.end());
        if (a.length() < b.length())
        {
            for (int i = a.length() - 1; i >= 0; i--)
                cout << a[i];
            cout << endl;
            continue;
        }
        else
        {
            c = a;
            for (int i = 0; i < a.length(); i++)
            {
                a = c;
                for (int j = i; j < a.length(); j++)
                {
                    swap(a[i], a[j]);
                    if (a <= b)
                    {
                        c = a;
                    }
                }
            }
            cout << a << endl;
        }
    }
    return 0;
}
