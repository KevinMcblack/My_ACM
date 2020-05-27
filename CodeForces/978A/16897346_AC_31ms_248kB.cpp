#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int a[100];
    int b[100];
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(a[j]==a[i]){
                    a[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                b[cnt++]=a[i];
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
