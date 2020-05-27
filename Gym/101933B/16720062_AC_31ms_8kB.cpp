/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-29 16:16:31 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-29 17:09:47
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n)
    {
        string s;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            if(s!=to_string(i)&&s!="mumble")
                flag=1;
        }
        if(flag)
            cout<<"something is fishy"<<endl;
        else
            cout<<"makes sense"<<endl;
    }
    return 0;
}
