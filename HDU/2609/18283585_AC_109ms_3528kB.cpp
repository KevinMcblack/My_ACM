#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
string s;
set<string> loopSet;
char temp[5000];
void get_min(string s)
{
    int i = 0, j = 1, k = 0, t;
    int len = s.size();
    while (i < len && j < len && k < len)
    {
        t = s[(i + k) % len] - s[(j + k) % len];
        if (t==0)
        {
            k++;
        }
        else
        {
            if (t > 0)
            {
                i += k + 1;
            }
            else
            {
                j += k + 1;
            }
            if (i == j)
            {
                j++;
            }
            k = 0;
        }
    }
    int ans = min(i, j);
    for (int i = 0; i < len; i++)
    {
        temp[i] = s[(ans + i) % len];
        //cout<<temp[i]<<endl;
    }
    //temp[len]='\0';
    //cout<<temp<<endl;
    loopSet.insert(temp);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        loopSet.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            get_min(s);
        }
        cout << loopSet.size() << endl;
    }
    return 0;
}
