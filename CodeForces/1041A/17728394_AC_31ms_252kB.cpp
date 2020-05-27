/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-15 16:33:23 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-15 16:37:38
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        int a[1005];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int cnt=0;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]>1){
                cnt+=(a[i]-a[i-1])-1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
