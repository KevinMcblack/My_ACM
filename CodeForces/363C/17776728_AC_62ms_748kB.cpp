/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-17 14:56:40 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-17 15:34:09
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
int main(int argc, char const *argv[])
{
    string s;
    while(cin>>s){
        int len=s.length();
        if(len<3){
            cout<<s<<endl;
            continue;
        }else{
            cout<<s[0]<<s[1];
            for(int i=2;i<len;i++){
                if(s[i]==s[i-1]&&s[i-1]==s[i-2]){
                    continue;
                }else if(i>=3){
                    if(s[i]==s[i-1]&&s[i-2]==s[i-3]){
                        s[i-1]=s[i-2];
                    }else{
                        cout<<s[i];
                    }
                }else{
                    cout<<s[i];
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
