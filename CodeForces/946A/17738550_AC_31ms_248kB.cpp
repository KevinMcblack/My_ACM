/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-15 17:08:34 
 * @Last Modified by:   KevinMcblack 
 * @Last Modified time: 2019-01-15 17:08:34 
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        int a[150];
        long long sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<0){
                sum1+=a[i];
            }else{
                sum2+=a[i];
            }
        }
        cout<<sum2-sum1<<endl;
    }
    return 0;
}
