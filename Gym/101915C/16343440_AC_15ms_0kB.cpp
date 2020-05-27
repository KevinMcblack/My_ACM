/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-09 19:40:18 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-09 19:50:48
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while(n--)
    {
        long long k,p,y;
        cin>>k>>p>>y;
        if(p>=k)
        {
            cout<<0<<endl;
            continue;
        }
        long long sum=0;
        sum=(k-p)*y;
        cout<<sum<<endl;
    }
    return 0;
}