#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int n,m,q;
string s1,s2;
int Next[1500];
void getNext()
{
    Next[0]=-1;
    int i=0,j=-1;
    while(i<m)
    {
        if(j==-1||s2[i]==s2[j])
        {
            i++;
            j++;
            Next[i]=j;
        }else{
            j=Next[j];
        }
    }
}
int kmp(int l,int r)
{
    int i=l-1,j=0;
    int ans=0;
    while(i<r)
    {
        if(s1[i]==s2[j]||j==-1)
        {
            i++;
            j++;
        }else{
            j=Next[j];
        }
        if(j==m)
        {
            ans++;
            j=Next[j];
        }
    }
    return ans;
}
int main()
{
    int a,b;
    while(cin>>n>>m>>q)
    {
        cin>>s1;
        cin>>s2;
        getNext();
        for(int i=0;i<q;i++)
        {
            cin>>a>>b;
            cout<<kmp(a,b)<<endl;
        }
    }
    return 0;
}