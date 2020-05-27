#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int t;
int Next[400000 + 5];
int res[400000 + 5];
string s1;

void getNext()
{
    int i = 0, j = -1;
    Next[0] = -1;
    int len = s1.size();
    while (i < len)
    {
        if (j == -1 || s1[i] == s1[j])
        {
            i++;
            j++;
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
    while (cin >> s1)
    {
        getNext();
        int len = s1.size();
        int ans = 0;
        for (int i = len; i>=1;)
        {
            res[ans++] = i;
            i = Next[i];
        }
        cout << res[ans - 1];
        for (int i = ans - 2; i >= 0; i--)
        {
            cout << " " << res[i];
        }
        cout << endl;
    }
    return 0;
}
