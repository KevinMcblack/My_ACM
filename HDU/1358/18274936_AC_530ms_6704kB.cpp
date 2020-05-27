#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int t, n;
string s;
int Next[1000005];
//求出所有前缀(满足是两个或两个以上的循环节组成的字符串)
void getNext() //得到Next数组
{
    int i = 0, j = -1;
    Next[0] = -1;
    int len = s.size(), t;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
        {
            i++;
            j++;
            t = i - j;//求循环节长度
            if (j && i % t == 0) //注意j不能等于0，否则循环节出现的次数为1，即：循环节为前i个字符.(不符题意)
            {
                cout << i << " " << i / t << endl;
            }
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}
int main()
{
    int cnt=1;
    ios::sync_with_stdio(false);
    while (cin >> n && n)
    {
        cin >> s;
        cout<<"Test case #"<<cnt++<<endl;
        getNext();
        cout<<endl;
    }
    return 0;
}
