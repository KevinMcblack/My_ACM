#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
char a[10005][80];
int Next[10005];

int getNext_c(int k)
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < m)
    {
        if (j == -1 || a[k][i] == a[k][j])
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
    return m - Next[m];
}

int getNext_r(int k)
{
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < n)
    {
        if (j == -1 || a[i][k] == a[j][k])
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
    return n - Next[n];
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%s",a[i]);
        }
        int h = -1, w = -1;
        for (int i = 0; i < n; i++)
        {
            h = max(h, getNext_c(i));
        }
        for (int i = 0; i < m; i++)
        {
            w = max(w, getNext_r(i));
        }
        // cout<<h<<endl;
        // cout<<w<<endl;
        printf("%d\n", h * w);
    }
    return 0;
}