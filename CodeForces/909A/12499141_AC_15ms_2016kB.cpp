#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stdlib.h> 
using namespace std;
string s,ss,s1="zzzzzzzzzz";
int main()
{
    cin>>s>>ss;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<ss.size();j++)
        {
            s1=min(s1,s.substr(0,i+1)+ss.substr(0,j+1));
        }
    }
    cout<<s1<<endl;
    return 0;
}