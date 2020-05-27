/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-25 18:35:20 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-25 18:40:17
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    int a[100];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        long long sum=1;
        long long temp=1;
        for(int i=n-1;i>=0;i--)
        {
            temp*=a[i];
            sum+=temp;
        }
        cout<<sum<<endl;
    }
    return 0;
}
