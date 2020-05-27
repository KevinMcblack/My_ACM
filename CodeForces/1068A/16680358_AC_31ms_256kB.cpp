#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

int main(int argc, char const *argv[])
{
    ll n, m, k, l;
    while (cin >> n >> m >> k >> l)
    {
        ll res=ceil((l+k)*1.0/m);
        if(n-k<l||floor(n*1.0/m)<res)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<res<<endl;
    }
    return 0;
}
