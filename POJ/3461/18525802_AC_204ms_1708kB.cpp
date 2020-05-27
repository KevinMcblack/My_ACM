#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int t;
int Next[10010];
string s1, s2;

void getNext()
{
    int i=0,j=-1;
    Next[0]=-1;
    int len=s1.size();
    while(i<len)
    {
        if(j==-1||s1[i]==s1[j])
        {
            i++;
            j++;
            Next[i]=j;
        }else{
            j=Next[j];
        }
    }
}
int kmp()
{
    int len1=s1.size();
    int len2=s2.size();
    int i=0,j=0;
    int res=0;
    while(i<len2)
    {
        if(s1[j]==s2[i]||j==-1)
        {
            i++;
            j++;

        }else
        {
            j=Next[j];
        }
        if(j==len1)
        {
            res++;
            j=Next[j];
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        getNext();
        int ans = kmp();
        cout << ans << endl;
    }
    return 0;
}
