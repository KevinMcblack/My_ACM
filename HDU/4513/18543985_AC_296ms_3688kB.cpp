#include <iostream>
#include <algorithm>

// 数组arr_new[i]：代表添加了“#”后的字符串。
// 数组p[i]：代表以字符串第i位为中心的回文串的最大半径。
// 变量mx ：代表当前“已经匹配完毕的结尾最远的回文串”到达了arr_new[]数组的第mx位。
// 变量id ：代表当前“已经匹配完毕的结尾最远的回文串”中心为arr_new[]数组的第id位。
using namespace std;
int n;
int arr[100005];
int arr_new[100005<<1];
int p[100005<<1];
int init()
{
    arr_new[0]=-1;
    arr_new[1]=0;
    int j=2;
    for(int i=0;i<n;i++)
    {
        arr_new[j++]=arr[i];
        arr_new[j++]=0;
    }
    arr_new[j]='\0';
    return j;
}
int manacher()
{
    int len=init();
    int max_len=-1;
    int id;
    int mx=0;
    for(int i=1;i<len;i++)
    {
        if(i<mx)
        {
            p[i]=min(p[2*id-i],mx-i);
        }else{
            p[i]=1;
        }

        while(arr_new[i-p[i]]==arr_new[i+p[i]])
        {
            if(arr_new[p[i]+i]==0)
            {
                p[i]++;
                continue;
            }else if(arr_new[p[i]+i]<=arr_new[p[i]+i-2])
            {
                p[i]++;
            }else{
                break;
            }
            
        }
        if(mx<p[i]+i)
        {
            mx=p[i]+i;
            id=i;
        }
        max_len=max(max_len,p[i]-1);
    }
    return max_len;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("%d\n", manacher());
    }
    return 0;
}