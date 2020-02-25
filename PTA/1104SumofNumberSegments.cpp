#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int main(int argc, char const *argv[])
{
    double a[maxn];
    int n;
    while (cin >> n)
    {
        double res = 0;
        int p = n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            res+=(a[i]*p*(i+1));
            p--;
        }
        printf("%.2lf\n", res);
    }
    return 0;
}
