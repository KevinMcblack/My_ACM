#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1000005;
string s;
int n;
int Next[maxn];
int res[maxn];
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
    int t;
    cin >> t;
    int test = 1;
    while (t--)
    {
        cin >> s;
        n = s.size();
        getNext();
        int cnt = 0;
        for (int i = n; i > 0; i=Next[i])
        {
            res[cnt++] = n - Next[i];
        }
        cout << "Case #" << test++ << ":"
             << " " << cnt << endl;
        cout << res[0];
        for (int i = 1; i < cnt; i++)
        {
            cout << " " << res[i];
        }
        cout << endl;
    }
    return 0;
}