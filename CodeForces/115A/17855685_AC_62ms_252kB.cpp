#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cctype>
using namespace std;

int n;

int main(int argc, char const *argv[])
{
    int a[2500];
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int tmp=0;
        int maxx=0;
        for(int i=1;i<=n;i++){
            tmp=0;
            for(int j=i;j<=n&&j!=-1;j=a[j]){
                tmp++;
            }
            maxx=max(maxx,tmp);
        }
        cout<<maxx<<endl;
    }
    return 0;
}
