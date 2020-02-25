#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
map <char,int> m;
int main()
{
    int n;
    string s;
    while(cin>>n>>s){
        m.clear();
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        int flag=0;
        for(int i=0;i<m.size();i++){
            if(m[i]>=2)
            {
                flag=1;
                break;
            }
        }
        if(n==1)
            flag=1;
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}