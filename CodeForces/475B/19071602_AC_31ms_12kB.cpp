#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <string>
using namespace std;
const int maxn = 1e4 + 5;

int n,m;
string h,v;
int main()
{
    while(cin>>n>>m)
    {
        cin>>h>>v;
        int flag=0;
        if(h[0]=='>'&&h[n-1]=='<'&&v[m-1]=='v'&&v[0]=='^')
        {
            flag=1;
        }else if(h[0]=='<'&&h[n-1]=='>'&&v[m-1]=='^'&&v[0]=='v'){
            flag=1;
        }
        if(flag)
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}