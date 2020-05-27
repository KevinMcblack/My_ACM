#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
int main(int argc, char const *argv[])
{
    int n;
    int a[maxn],b[maxn];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=1+max(a[i],b[i]);
        }
        cout<<sum<<endl;
    }
    return 0;
}
