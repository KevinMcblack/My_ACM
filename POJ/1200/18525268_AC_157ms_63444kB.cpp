#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
char s[16000000+500];
int vis[256];
int in[16000000+500];
int main()
{
    int n, nc;
    while (~scanf("%d%d", &n, &nc))
    {
        memset(vis, 0, sizeof(vis));
        memset(in, 0, sizeof(in));
        scanf("%s", s);
        int len = strlen(s);
        int k=0;
        for (int i = 0; i < len; i++)
        {
            if(!vis[s[i]])
            {
                vis[s[i]]=k++;
            }
           
        }
        int ans = 0;
        for (int i = 0; i <= len - n; i++)
        {
            int sum = 0;
            for (int j = i; j < i + n; j++)
            {
                sum = sum * nc + vis[s[j]];
            }
            if (!in[sum])
            {
                in[sum] = 1;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}