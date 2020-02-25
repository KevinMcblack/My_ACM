#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    string s;
    while(cin>>n)
    {
        cin>>s;
        if(n<11)
        {
            cout<<0<<endl;
            continue;
        }
        int len=s.size();
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='8')
            {
                cnt++;
            }
        }
        if(cnt==0)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<min(n/11,cnt)<<endl;
    }
    return 0;
}
