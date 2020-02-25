#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        deque<int> v;
        int a,b;
        long long sum=0;
        int t;
        t=sqrt(n);
        for(int i=0;i<n/2;i++){
            cin>>a>>b;
            sum+=abs(a-b);
            v.push_back(max(a,b));
        }
        for(int i=0;i<t;i++){
            for(int j=0;j<v.size();j+=2){
                sum+=abs(v[j+1]-v[j]);
                v.push_back(max(v[j+1],v[j]));
                v.pop_front();
                v.pop_front();
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
