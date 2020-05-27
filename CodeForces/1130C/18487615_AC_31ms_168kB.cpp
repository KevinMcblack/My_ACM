#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n;
int x[2],y[2];
char m[55][55];
int v[2][55][55];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y,int c)
{
    if(v[c][x][y])
    {
        return ;
    }
    v[c][x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(m[nx][ny]=='0')
        {
            dfs(nx,ny,c);
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {   
        memset(v,0,sizeof(v));
        for(int i=0;i<2;i++)
        {
            cin>>x[i]>>y[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>m[i][j];
            }
        }

        // for(int i=1;i<=n;i++)
        // {
        //    for(int j=1;j<=n;j++)
        //    {
        //        cout<<m[i][j];
        //    }
        //    cout<<endl;
        // }

        for(int i=0;i<2;i++){
            dfs(x[i],y[i],i);
        }
        int res=0x3f3f3f3f;
        for(int a=1;a<=n;a++)
        {
            for(int b=1;b<=n;b++)
            {
                if(v[0][a][b])
                {
                    for(int c=1;c<=n;c++)
                    {
                        for(int d=1;d<=n;d++)
                        {
                            if(v[1][c][d])
                            {
                                res=min(res,(d-b)*(d-b)+(c-a)*(c-a));
                            }
                        }
                    }
                }
            }
        }
        cout<<res<<endl;
    }   
    return 0;
}