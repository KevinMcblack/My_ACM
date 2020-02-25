#include <iostream>
using namespace std;
const int maxn=2005;
int rec[maxn][maxn];
int col[maxn],row[maxn];
int dir[]
void dfs(int si,int sj)
{

}
int main(int argc, char const *argv[])
{
    int n,m;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            cin>>col[i];
        for(int i=0;i<m;i++)
            cin>>row[i];
        int minn=0x3f3f3f3f3f;
        int si,sj;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                rec[i][j]=col[i]*row[j];
                if(rec[i][j]<minn)
                {
                    minn=rec[i][j];
                    si=i;
                    sj=j;
                }
            }
        dfs(si,sj);
    }
    return 0;
}
