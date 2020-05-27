#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 1000017;
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
    ios::sync_with_stdio(false);
    while (cin >> s)
    {
        if (s == ".")
        {
            break;
        }
        n = s.size();
        getNext();
        int sum = n - Next[n];
        if (n % sum != 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << n / sum << endl;
        }
    }

    return 0;
}