#include <stdio.h>
int t, n, m;
int s[1000010];
int a[10010];
int next[10010];
void getNext() //得到next数组
{
    int i = 0, j = -1;
    next[0] = -1;
    while (i < m)
    {
        if (j == -1 || a[i] == a[j])
        {
            i++;
            j++;
            if (a[i] == a[j]) //如果还是相等  就继续优化
            {
                next[i] = next[j];
            }
            else
                next[i] = j;
        }
        else
            j = next[j];
    }
}
int kmp() //序列的匹配
{
    int i = 0, j = 0; //2个都设为0
    while (i < n && j < m)
    {
        if (a[j] == s[i] || j == -1) //相等 就比较下一个
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if (j > m - 1) //返回第几个开始
        return i - m + 1;
    else
        return -1;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        if (n < m)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &s[i]);
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &a[i]);
        }
        getNext();
        int ans = kmp();
        printf("%d\n", ans);
    }
    return 0;
}
