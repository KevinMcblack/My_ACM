
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 102400;


int main()
{
    int t;
    cin>>t;
    while(t--){
        int a[5];
        cin>>a[1]>>a[2]>>a[3]>>a[4];
        int cnt=0;
        for(int i=1;i<=4;i++){
            if(a[i]==0){
                cnt++;
            }
        }
        if(cnt==4){
            cout<<"Typically Otaku"<<endl;
        }else if(cnt==3){
            cout<<"Eye-opener"<<endl;
        }else if(cnt==2){
            cout<<"Young Traveller"<<endl;
        }else if(cnt==1){
            cout<<"Excellent Traveller"<<endl;
        }else if(cnt==0){
            cout<<"Contemporary Xu Xiake"<<endl;
        }
    }
    return 0;
}
