#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int t;
int Next[10010];
string s1, s2;

void getNext() //得到Next数组
{
    int i = 0, j = -1;
    Next[0] = -1;
    int m = s1.size();
    while (i < m)
    {
        if (j == -1 || s1[i] == s1[j])
        {
            i++;
            j++;
            if (s1[i] == s1[j]) //如果还是相等  就继续优化
            {
                Next[i] = Next[j];
            }
            else
                Next[i] = j;
        }
        else
            j = Next[j];
    }
}
int kmp() //序列的匹配
{
    int res = 0;
    int i = 0, j = 0; //2个都设为0
    int m = s2.size(), n = s1.size();
    while (i < m)
    {
        if (s1[j] == s2[i] || j == -1) //相等 就比较下一个
        {
            i++;
            j++;
        }
        else
        {
            j = Next[j];
        }

        if (j == n)
        {
            j = 0;
            res++;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin >> s2)
    {
        if(s2=="#"){
            break;
        }
        cin>>s1;
        getNext();
        int ans = kmp();
        cout << ans << endl;
    }
    return 0;
}
