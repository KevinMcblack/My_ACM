#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
string s;
int Next[1000005];
int len;
void getNext()
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
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

int get_min()
{
    int i = 0, j = 1, k = 0, t;
    while (i < len && j < len && k < len)
    {
        t = s[(i + k) % len] - s[(j + k) % len];
        if (!t)
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
    return min(i, j);
}

int get_max()
{
    int i = 0, j = 1, k = 0, t;
    while (i < len && j < len && k < len)
    {
        t = s[(i + k) % len] - s[(j + k) % len];
        if (!t)
        {
            k++;
        }
        else
        {
            if (t < 0)
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
    return min(i, j);
}

int main()
{
    while (cin >> s)
    {
        len = s.size();
        getNext();
        int res = len - Next[len];
        if (len % res == 0)
        {
            int temp = len / res;
            cout << get_min()+1 << " " << temp << " " << get_max()+1 << " " << temp << endl;
        }
        else
        {
            cout << get_min()+1 << " " << 1 << " " << get_max()+1 << " " << 1 << endl;
        }
    }
    return 0;
}