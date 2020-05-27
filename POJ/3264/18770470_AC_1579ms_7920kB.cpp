#include <cstdio>
#include <cmath>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
int n, q;
int st1[50005][20], st2[50005][20];
void init()
{
    for (int i = 1; (1 << i) <= n; i++)
    {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            st1[j][i] = min(st1[j][i - 1], st1[j + (1 << (i - 1))][i - 1]);
            st2[j][i] = max(st2[j][i - 1], st2[j + (1 << (i - 1))][i - 1]);
        }
    }
}
int getans(int l, int r)
{
    int t = 0; //=log(r-l+1)/log(2);
    for (; (1 << (t + 1)) <= r - l + 1; t++)
        ;
    int mid = min(st1[l][t], st1[r - (1 << t) + 1][t]);
    int mxd = max(st2[l][t], st2[r - (1 << t) + 1][t]);
    return mxd - mid;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &st1[i][0]);
        st2[i][0] = st1[i][0];
    }
    init();
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", getans(l, r));
    }
    return 0;
}