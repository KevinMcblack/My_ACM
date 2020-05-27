#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string s;
    while(cin>>n){
       cin>>s;
       int len=s.size();
       int cnt=0;
       for(int i=2;i<len;i++){
           if(s[i]=='x'&&s[i-1]=='x'&&s[i-2]=='x')
                cnt++;
       }
       cout<<cnt<<endl;
    }
    return 0;
}
