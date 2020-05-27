#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int a[150];
        int u=0,d=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>0) u++;
            if(a[i]<0) d++;
        }
        int temp=ceil(n*1.0/2*1.0);
        // cout<<"temp:"<<temp<<endl;
        if(u>=temp)
        {
            cout<<1<<endl;
        }else if(u<temp)
        {
            if(d>=temp)
            {
                cout<<-1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}