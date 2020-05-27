#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

string s1, s2;
map<char, char> m;
int Next[100005];
int len;
void getNext()
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < len)
    {
        if (j == -1 || s2[i] == m[s2[j]])
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

    int t;
    cin >> t;
    while (t--)
    {
        m.clear();
        cin >> s1;
        cin >> s2;
        for (int i = 0; i < 26; i++)
        {
            m[s1[i]] = i + 'a';
        }
        len = s2.size();
        getNext();
        int ans = len - Next[len];
        if (Next[len] > ((len + 1) / 2))
        {
            ans = (len + 1) / 2;
        }
        for (int i = 0; i < ans; i++)
        {
            cout << s2[i];
        }
        for (int i = 0; i < ans; i++)
        {
            cout << m[s2[i]];
        }
        cout << endl;
    }
    return 0;
}