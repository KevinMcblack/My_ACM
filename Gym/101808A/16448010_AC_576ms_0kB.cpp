/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-15 18:30:31 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-15 18:34:34
 */
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        long long R,r;
        cin>>R>>r;
        if(R*R>2*(r*r))
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }
    return 0;
}
