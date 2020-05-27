/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-09 19:27:52 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-09 19:36:47
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
        int a;
        int t[100];
        cin>>a;
        for(int i=0;i<a-1;i++)
        {
            cin>>t[i];
        }
        int i;
        for(i=0;i<a-1;i++)
        {
            if(t[i]!=(i+1))
            {
                cout<<i+1<<endl;
                break;
            }
        }
        if(i==a-1)
            cout<<a<<endl;
    }
    return 0;
}
