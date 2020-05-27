#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
#define MAXN 100010  
  
int dp[MAXN];//d[i]表示石块能组成的高度为i  
  
struct Node  
{  
    int h,a,c;//分别表示一块砖的高度、用这种砖的最大高度和最多块数  
} s[MAXN];  
int cmp(Node x,Node y)//结构体排序  
{  
    return x.a<y.a;//升序  
}  
int main()  
{  
    int n,i,j,ans=0;  
    cin>>n;  
    for(i=0; i<n; ++i)  
        cin>>s[i].h>>s[i].a>>s[i].c;  
    sort(s,s+n,cmp);//按最大高度升序排列  
    memset(dp,-1,sizeof dp);  
    dp[0]=0;  
    for(i=0; i<n; i++)//多重部分和  
        for(j=0; j<=s[i].a; j++)  
        {  
            if (dp[j]>=0) dp[j]=s[i].c;  
            else if (j<s[i].h || dp[j-s[i].h] <=0) dp[j]=-1;  
            else dp[j] = dp[j-s[i].h]-1;  
        }  
    for (i=s[n-1].a; i>=0; --i)  
        if(dp[i]>=0)  
        {  
            ans=i;  
            break;  
        }  
    cout<<ans<<endl;  
    return 0;  
}  