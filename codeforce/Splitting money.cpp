#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int main(int argc, char const *argv[])
{
    int n;
    int x,f;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>x>>f;
        long long sum=0;
        for(int i=0;i<n;i++){
            if(a[i]>x){
                int mul=ceil((double)(a[i]-x)/(double)(x+f));
                sum+=f*mul;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
