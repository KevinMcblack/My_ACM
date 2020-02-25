#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int a[150];
    while(cin>>n){
        int maxx=-1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            maxx=max(maxx,a[i]);
            sum+=a[i];
        }
        int temp=0;
        for(int i=maxx;;i++)
        {
            temp=0;
            for(int j=0;j<n;j++)
                temp+=(i-a[j]);
            if(temp>sum){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
