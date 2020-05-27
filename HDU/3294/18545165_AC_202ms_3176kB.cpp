#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char s[200005];
char s_new[200005 << 1];
int p[200005 << 1];
char c;
int r, mid;
int Init()
{
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';
    return j;
}

void Manacher()
{
    int len = Init();
    int id;
    int mx = 0;
    r = 0, mid = 0;
    for (int i = 1; i < len; i++)
    {
        if (i < mx)
        {
            p[i] = min(p[2 * id - i], mx - i);
        }
        else
        {
            p[i] = 1;
        }
        while (s_new[i + p[i]] == s_new[i - p[i]])
        {
            p[i]++;
        }
        if (mx < i + p[i])
        {
            mx = i + p[i];
            id = i;
        }
        if (r < p[i] - 1)
        {
            r = p[i] - 1;
            mid = i;
        }
    }
}

int main()
{
    while (~scanf("%c", &c))
    {
        scanf("%s", s);
        getchar();
        Manacher();
        if (r < 2)
        {
            printf("No solution!\n");
            continue;
        }
        int start = (mid - r - 1) / 2;
        int end = (mid + r - 3) / 2;
        printf("%d %d\n", start, end);
        int temp = c - 'a';
        for (int i = start; i <= end; i++)
        {
            s[i] -= temp;
            if (s[i] < 'a')
            {
                s[i] += 26;
            }
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}