
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, a, b;
    int num[100];
    while (cin >> n >> a >> b)
    {
        for (int i = 0; i < n; i++)
            cin >> num[i];
        int sum = 0;
        int flag = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (num[i] != num[n - i - 1])
            {
                if (num[i] == 2)
                {
                    if (num[n - i - 1] == 0)
                        sum += a;
                    else if (num[n - i - 1] == 1)
                        sum += b;
                }
                else if (num[n - i - 1] == 2)
                {
                    if (num[i] == 0)
                        sum += a;
                    else if (num[i] == 1)
                        sum += b;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                if (num[i] == 2 || num[n - i - 1] == 2)
                {
                    sum += 2 * min(a, b);
                }
            }
        }
        if (flag)
        {
            cout << -1 << endl;
        }
        else
        {
            if (n & 1)
            {
                if (num[n / 2] == 2)
                    cout << sum + min(a, b) << endl;
                else
                    cout << sum << endl;
            }
            else
            {
                cout << sum << endl;
            }
        }
    }
    return 0;
}
