#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 400005;
string s;
int n;
int Next[maxn];
int ans[maxn];
void getNext()
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < n)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++, j++;
            Next[i] = j; 
        }
        else
        {
            j = Next[j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> s)
    {
        n = s.size();
        getNext();
        int j=0;
        for(int i=n;Next[i]!=-1;){
            ans[j++]=i;
            i=Next[i];
        }
        for(int i=j-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout << endl;
    }

    return 0;
}