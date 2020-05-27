/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-16 09:13:24 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-16 09:35:48
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    long long a[3];
    while(cin>>a[0]>>a[1]>>a[2]){
        sort(a,a+3);
        long long sum=0;
        if(a[2]-a[1]>1){
            sum+=((a[2]-a[1])-1);
        }
        
        if(a[2]-a[0]>1){
            sum+=((a[2]-a[0])-1);
        }
        cout<<sum<<endl;
    }
    return 0;
}
