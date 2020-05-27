/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-31 20:03:01 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-31 20:31:17
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string s;
    while(cin>>s){
        int pre[1005]={0};
        int len=s.size();
        for(int i=1;i<len-1;i++){
            if(s[i]!=s[i+1])
                pre[i]=1;
        }
        if(s[len-1]=='a')
            pre[len-1]=1;
        for(int i=0;i<len;i++){
            cout<<pre[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
