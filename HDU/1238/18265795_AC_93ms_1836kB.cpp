#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
string s[105];
int Next[105];
int preLen;
int pre;
string preS;
int inLen;
//使用KMP求 多个字符串 最长公共子序列的长度
void getNext(string s)
{
    int i = 0, j = -1;
    Next[0] = -1;
    int len = s.size();
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
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

bool kmp(string ss, string temp)
{
    int len = ss.size();
    int i = 0, j = 0;
    while (i < len && j < inLen)
    {
        if (ss[i] == temp[j] || j == -1)
        {
            i++;
            j++;
        }
        else
        {
            j = Next[j];
        }
    }
    if (j > inLen - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        preLen = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            int temp = s[i].size();
            if (temp < preLen)
            {
                preLen = temp;
                pre = i;
                preS = s[i];
            }
        }

        bool flag = true;
        int maxx = 0;
        for (int j = 0; j < preLen; j++)
        {
            for (int k = j + 1; k <= preLen; k++)
            {
                inLen = k - j;
                string temp = preS.substr(j, k);
                getNext(temp);
                flag = true;
                for (int i = 0; i < n; i++)
                {
                    if (i != pre)
                    {
                        if (kmp(s[i], temp) == false)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    maxx = max(maxx, inLen);
                    continue;
                }
                flag = true;
                temp = temp.assign(temp.rbegin(), temp.rend());
                getNext(temp);
                for (int i = 0; i < n; i++)
                {
                    if (i != pre)
                    {
                        if (kmp(s[i], temp) == false)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    maxx = max(maxx, inLen);
                }
            }
        }
        cout << maxx << endl;
    }
    return 0;
}