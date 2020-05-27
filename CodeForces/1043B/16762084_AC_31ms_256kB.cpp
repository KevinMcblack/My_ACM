#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int a[1500];
    int b[1500];
    int c[1500];
    while(cin>>n){
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i>=1)
                b[i]=a[i]-a[i-1];
        }
        b[0]=a[0];
        int cnt=0;
        int temp=0;
        for(int i=1;i<=n;i++)
        {
            temp=0;
            int flag=0;
            long long sum=0;
            for(int j=0;;j++)
            {
                sum+=b[j%i];
                if(sum==a[temp])
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
                if(temp==n-1){
                    break;
                }
                temp++;
            }
            if(flag)
            {
                c[cnt]=i;
                cnt++;
            }
        }
        
                cout<<cnt<<endl;
                for(int i=0;i<cnt;i++){
                cout<<c[i]<<" ";
            }
            cout<<endl;
        
        
    }
    return 0;
}
