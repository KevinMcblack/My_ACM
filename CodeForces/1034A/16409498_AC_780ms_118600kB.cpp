/*
 * @Author: KevinMcblack 
 * @Date: 2018-10-13 15:34:42 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2018-10-13 16:02:06
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=3e5;
const int maxa=1.5e7;
int vis[maxa],cnt[maxa];
int a[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin>>n;
    int gcd=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        gcd=__gcd(gcd,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]/gcd]++;
    }
    int res=0;
    for(int i=2;i<=maxa;i++)
    {
        int temp=0;
        if(vis[i]==0)
        {
            for(int j=i;j<=maxa;j+=i)  
            {
                vis[j]=1;
                temp+=cnt[j];
            }
            res=max(res,temp);
        }
    }
    cout<<(res ? n - res : -1)<<endl;
    return 0;
}