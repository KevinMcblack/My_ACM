#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=2050+7;
int n,m,k;
int c[N][N],r[N][N];
char ch;
int main()
{
    int ans=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>ch;
            r[i][j]=r[i][j-1];
            c[i][j]=c[i-1][j];
            if(ch=='*')
            {
                r[i][j]++;
                c[i][j]++;
            }
            if(i>=k&&c[i-k][j]==c[i][j]) ans++;
            if(j>=k&&r[i][j-k]==r[i][j]) ans++;
        }
    }
    printf("%d\n",k==1?ans/2:ans);
    return 0;
}