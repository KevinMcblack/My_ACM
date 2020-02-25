#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
map<char,int> m;
int main(int argc, char const *argv[])
{
    string s1,s2;
    while(cin>>s1>>s2){
        m.clear();
        int len1=s1.size();
        int len2=s2.size();
        for(int i=0;i<len1;i++)
            m[s1[i]]++;
        for(int i=0;i<len2;i++)
            m[s2[i]]++;
        int flag=0;
        for(int i=0;i<m.size();i++)
        {
            if(m[i]&1)
            {
                flag++;
            }   
        }
        if(flag>=2)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
