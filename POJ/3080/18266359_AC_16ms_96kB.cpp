#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
const int maxn = 15;
char str[maxn][200];
int len[maxn];
int main()
{
    int n;
    int test;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        char temp[200];
        char ans[200];
        int max = 0, t;
        int minnum = 0;
        int min = 10000;
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str[i]);
            len[i] = strlen(str[i]);
            if (len[i] < min)
            {
                min = len[i];
                minnum = i;
            }
        }
        for (int i = 0; i <= min - 2; i++)
        {
            for (int o = 1; o <= min - i; o++)
            {
                int k = 0;
                for (int j = i; j <= min - o; j++)
                {
                    temp[k++] = str[minnum][j];
                }
                temp[k] = '\0';
                for (t = 1; t <= n; t++)
                {
                    if (t == minnum)
                        continue;
                    char *p = strstr(str[t], temp);
                    if (p == NULL)
                    {
                        break;
                    }
                }
                if (t == n + 1)
                {
                    if (k == max)
                    {
                        if (strcmp(ans, temp) > 0)
                            strcpy(ans, temp);
                    }
                    if (k > max)
                    {
                        max = k;
                        strcpy(ans, temp);
                    }
                }
            }
        }
        if (max < 3)
        {
            printf("no significant commonalities\n");
        }
        else
        {
            puts(ans);
        }
    }
    return 0;
}