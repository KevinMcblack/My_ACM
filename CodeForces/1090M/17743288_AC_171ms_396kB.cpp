/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-16 14:05:53 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-16 14:12:35
 */
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main(int argc, char const *argv[])
{
    int n,k;
    while(cin>>n>>k){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int maxLength=1;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                cnt++;
                maxLength=max(maxLength,cnt);
            }else{
                cnt=1;
            }
        }
        cout<<maxLength<<endl;
    }
    return 0;
}