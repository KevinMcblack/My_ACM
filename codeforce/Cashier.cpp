/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-11 19:47:55 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-11 20:27:25
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,l,a;
    int ti,li;
    while(cin>>n>>l>>a)
    {
        int res=0;
        int k=0;
        for(int i=0;i<n;i++)
        {
            cin>>ti>>li;
            res+=(ti-k)/a;
            k=ti+li;
        }
        res+=(l-k)/a;
        cout<<res<<endl;
    }
    return 0;
}
