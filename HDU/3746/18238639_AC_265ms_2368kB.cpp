#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 100005;
string s;
int n;
int Next[maxn];
void getNext()
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < n)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++, j++;
            if (s[i] == s[j])
            {
                Next[i] = Next[j];
            }
            else
            {
                Next[i] = j;
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
    //ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        n = s.size();
        getNext();
        int sum = n - Next[n];
        if (Next[n] == 0)
        {
            cout << n << endl;
        }
        else
        {
            if (n % sum != 0)
            {
                cout << sum - n % sum << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}