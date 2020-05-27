#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int n;
string s;
int Next[200005];
long long res;
//主串的前缀 在主串出现的次数和
void getNext()
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < n)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            Next[i] = j;
            if (Next[i] >0)
            {
                res ++;
            }
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
    while (t--)
    {
        cin >> n;
        cin >> s;
        res = 0;
        getNext();
        cout << (res+n) % 10007 << endl;
    }
    return 0;
}