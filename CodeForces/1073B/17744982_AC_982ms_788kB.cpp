/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-16 14:47:01 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-16 15:03:36
 */
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=1e5+5;
int a[maxn*2];
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        int temp;
        for(int i=1;i<=n;i++){
            cin>>temp;
            a[temp]=i;
        }
        int s=0;
        for(int i=1;i<=n;i++){
            cin>>temp;
            if(a[temp]<s){
                cout<<"0 ";
            }else{
                cout<<a[temp]-s<<" ";
                s=a[temp];
            }
        }
        cout<<endl;
    }
    return 0;
}