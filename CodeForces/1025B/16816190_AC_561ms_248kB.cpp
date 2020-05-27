#include <iostream>
#include <algorithm>
using namespace std;
typedef  long long ll;
ll check(ll value){
    for(int i=2;i*i<=value;i++){
        if(value%i==0)
            return i;
    }
    return value;
}
int main(int argc, char const *argv[])
{
    int n;        
    ll a,b;
    ll tempa,tempb;
    while(cin>>n>>tempa>>tempb){
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            tempa=__gcd(tempa,a*b);
            tempb=__gcd(tempb,a*b);
        }
        if(tempa!=1){
            cout<<check(tempa)<<endl;
        }else if(tempb!=1){
            cout<<check(tempb)<<endl;
        }else{
            cout<<-1<<endl;
        }

    }
    return 0;
}
