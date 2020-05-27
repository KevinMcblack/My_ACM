/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-17 14:33:02 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-17 14:41:34
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        long long sumA=0,sumB=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        int ra=n-1,rb=n-1;
        for(int i=0;i<n;i++){
            if(a[ra]>b[rb]){
                sumA+=a[ra];
                ra--;
            }else{
                rb--;
            }
            if(a[ra]<b[rb]){
                sumB+=b[rb];
                rb--;
            }else{
                ra--;
            }
        }
        cout<<sumA-sumB<<endl;
    }
    return 0;
}
