#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
char maps[5][5];
int maxx;

int judge(int n,int m)
{
    for(int i=n-1;i>=0;i--)
    {
        if(maps[i][m]=='O')
        {
            return 0;
        }
        if(maps[i][m]=='X')
        {
            break;
        }
    }
    for(int i=m-1;i>=0;i--)
    {
        if(maps[n][i]=='O')
        {
            return 0;
        }
        if(maps[n][i]=='X')
        {
            break;
        }
    }
    return 1;
}
void dfs(int k,int num)
{
    if(k==n*n)
    {
        maxx=max(maxx,num);
        return ;
    }else{
        int x=k/n;//行数
        int y=k%n;//列数

        if(maps[x][y]=='.'&&judge(x,y))
        {
            maps[x][y]='O';
            dfs(k+1,num+1);
            maps[x][y]='.';
        }
        dfs(k+1,num);
    }
}

int main()
{
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",&maps[i]);
        }
        maxx=0;
        dfs(0,0);
        printf("%d\n",maxx);
    }
    return 0;
}