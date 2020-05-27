/*
 * @Author: KevinMcblack 
 * @Date: 2019-01-16 10:09:02 
 * @Last Modified by: KevinMcblack
 * @Last Modified time: 2019-01-16 13:14:57
 */

#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;

struct number{
    long long maxnum;
    long long num;
}a[maxn*2];

int main(int argc, char const *argv[])
{
    int t;
    while(cin>>t){
        long long  n;
        long long  temp;
        long long  maxx=-1,maxAll=-1;
        long long  length=0;
        long long sum=0;
        for(long long  i=0;i<t;i++){
            cin>>n;
            maxx=0;
            for(int j=0;j<n;j++){
                cin>>temp;
                if(maxx<temp){
                    maxx=temp;
                }
            }
            a[length].num=n;
            a[length].maxnum=maxx;
            length++;
            maxAll=max(maxAll,maxx);
        }
        for(long long  i=0;i<length;i++){
            sum+=(maxAll-a[i].maxnum)*a[i].num;
        }
        cout<<sum<<endl;
    }
    return 0;
}